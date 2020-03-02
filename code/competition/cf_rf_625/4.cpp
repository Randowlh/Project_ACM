#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int n, m;
map<int, vector<int>> M;
int book[200100];
int t[200100];
int nn[200100];
void work()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int w, u;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &w, &u);
        M[w].push_back(u);
    }
    queue<pair<int, int>> q;
    t[1] = 1;
    q.push(make_pair(n, 1));
    book[n] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < M[q.front().first].size(); i++)
        {
            if (book[i] == 0)
            {
                nn[i] = q.front().second + 1;
                q.push(make_pair(i, q.front().second + 1));
                book[i] = 1;
                t[q.front().second + 1]++;
            }
        }
        q.pop();
    }
    int tmp;
    int k;
    scanf("%d", &k);
    int mi = 0;
    int ma = 0;
    for (int i = k; i >= 1; i--)
    {
        scanf("%d", &tmp);
        if (nn[tmp] == i)
        {
            if (t[nn[tmp]] >= 2)
            {
                ma++;
            }
        }
        else
        {
            mi++;
            ma++;
        }
    }
    cout << mi << ' ' << ma << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}