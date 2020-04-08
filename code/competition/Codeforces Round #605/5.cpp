#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int dp[200000];
int a[200000];
int n;
int dfs(int x, int fl = 0)
{
    if (dp[x] != 0 && !fl)
        return dp[x];
    if (dp[x] > 0)
        return dp[x];
    int ans = inf - 100;
    dp[x] = -1;
    if (x - a[x] >= 0)
    {
        if (a[x] & 1 != a[x - a[x]] & 1)
            ans = 1;
        else
        {
            int t = dfs(x - a[x]);
            if (t != -1)
                ans = min(ans, t + 1);
        }
    }
    if (x + a[x] < n)
    {
        if (a[x] & 1 != a[x + a[x]] & 1)
            ans = 1;
        else
        {
            int t = dfs(x + a[x]);
            if (t != -1)
                ans = min(ans, t + 1);
        }
    }
    if (ans == inf - 100)
        ans = -1;
    dp[x] = ans;
    return ans;
}
void work()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dp[i]);
    }
    printf("\n");
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    //1 2 1 1 1 1 1 2 2 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 2 1 1 1 2 1 1 1 1 3 1 1 2 1 2 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 2 1 2 1 2 1 2 1 1 1 3 1 3 2 3 2 2 1
    while (t--)
    {
        work();
    }
    return 0;
}