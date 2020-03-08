#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int x, y, z;
    int v;
    bool operator==(node a) const
    {
        return x == a.x && y == a.y && z == a.z;
    }
    bool operator<(node a) const
    {
        if (x == a.x)
        {
            if (y == a.y)
            {
                if (z == a.z)
                    return v < a.v;
                return z < a.z;
            }
            return y < a.y;
        }
        return x < a.x;
    }
};
int biao[7][3] = {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 0}};
map<node, vector<int>> M;
map<node, int> bk;
vector<node> v;
void work()
{
    int n, m;
    cin >> n >> m;
    node a;
    for (int i = 0; i < n; i++)
    {
        cin >> a.x >> a.y >> a.z >> a.v;
        v.push_back(a);
        bk[a] = 1;
        int t = a.v;
        a.v = 0;
        M[a].push_back(t);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (bk[v[i]] == 1)
        {
            ans++;
            queue<node> q;
            q.push(v[i]);
            bk[v[i]] = 1;
            while (!q.empty())
            {
                node a = q.front();
                q.pop();
                node tmp;
                for (int i = 0; i < 7; i++)
                {
                    tmp.x = a.x + biao[i][0];
                    tmp.y = a.y + biao[i][1];
                    tmp.z = a.z + biao[i][2];
                    tmp.v = 0;
                    if (M.count(tmp) == 0)
                    {
                        continue;
                    }
                    for (int j = 0; j < M[tmp].size(); j++)
                    {
                        if (abs(M[tmp][j] - a.v) <= m)
                        {
                            node ts = tmp;
                            ts.v = M[tmp][j];
                            if (bk[ts] == 1)
                                q.push(ts);
                            bk[ts] = 2;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}