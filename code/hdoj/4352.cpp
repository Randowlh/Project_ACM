#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[25][11][11];
int disg[25];
int n, m, k;
int dfs(int pos, int pre, int staus, int flag)
{
    if (pos == 0)
        return staus == k;
    if (flag && dp[pos][pre][staus] != -1)
        return dp[pos][pre][staus];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (pre == 0)
            ans += dfs(pos - 1, i, 1, flag || i < num);
        else if (i > pre)
            ans += dfs(pos - 1, i, staus + 1, flag || i < num);
        else
            ans += dfs(pos - 1, pre, staus, flag || i < num);
    }
    if (flag && pre)
        dp[pos][pre][staus] = ans;
    return ans;
}
int calc(int x)
{
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    return dfs(cnt - 1, 0, 0, 0);
}
signed main()
{
    freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    int t;
    scanf("%lld", &t);
    for (int q = 1; q <= t; q++)
    {
        printf("Case #%lld: ", q);
        scanf("%lld%lld%lld", &n, &m, &k);
        printf("%lld\n", calc(m) - calc(n - 1));
    }
}