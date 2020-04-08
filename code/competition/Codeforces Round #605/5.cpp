#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int dp[200010];
int a[200010];
vector<int> mp[200010];
int n;
void work()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = inf;
    }
    for (int i = 0; i < n; i++)
    {
        if (i - a[i] >= 0 && a[i - a[i]] % 2 == a[i] % 2)
            mp[i - a[i]].push_back(i);
        if (i + a[i] < n && a[i + a[i]] % 2 == a[i] % 2)
            mp[i + a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (i - a[i] >= 0 && a[i - a[i]] % 2 != a[i] % 2)
            dp[i] = 1;
        if (i + a[i] < n && a[i + a[i]] % 2 != a[i] % 2)
            dp[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == 1)
        {
            queue<pair<int, int>> q;
            q.push(make_pair(1, i));
            while (!q.empty())
            {
                pair<int, int> x = q.front();
                q.pop();
                for (int i = 0; i < mp[x.second].size(); i++)
                {
                    if (dp[mp[x.second][i]] > x.first + 1)
                    {
                        dp[mp[x.second][i]] = x.first + 1;
                        q.push(make_pair(x.first + 1, mp[x.second][i]));
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == inf)
            printf("-1 ");
        else
            printf("%d ", dp[i]);
    }
    printf("\n");
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    //1 2 1 1 1 1 1 2 2 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 2 1 1 1 2 1 1 1 1 3 1 1 2 1 2 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 2 1 2 1 2 1 2 1 1 1 3 1 3 2 3 2 2 1
    while (t--)
    {
        work();
    }
    return 0;
}