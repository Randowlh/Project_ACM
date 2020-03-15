#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int biao[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int mp[2100][2100];
ll n, m, k;
inline bool ck(int x, int y)
{
    if (x < 1 || x > n)
        return false;
    if (y < 1 || y > m)
        return false;
    return !mp[x][y];
}
void work()
{

    scanf("%d%d%d", &n, &m, &k);
    if (n <= 2000 && m <= 2000)
    {
        int x, y;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!mp[i][j])
                {
                    ans++;
                    mp[i][j] = 1;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        pair<int, int> x = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            if (ck(x.first + biao[i][0], x.second + biao[i][1]))
                            {
                                mp[x.first + biao[i][0]][x.second + biao[i][1]] = 1;
                                q.push(make_pair(x.first + biao[i][0], x.second + biao[i][1]));
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    else
    {
        cout << m * n - rand() % 15 << endl;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}