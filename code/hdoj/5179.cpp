#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[10][10];
int disg[10];
int dfs(int pos, int staus, int flag)
{
    if (pos == 0)
        return staus != 0;
    if (flag && dp[pos][staus] != -1)
        return dp[pos][staus];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (i == 0)
        {
            if (staus == 0)
                ans += dfs(pos - 1, i, flag || i < num);
        }
        else if (staus % i == 0)
            ans += dfs(pos - 1, i, flag || i < num);
    }
    if (flag)
        dp[pos][staus] = ans;
    return ans;
}
int calc(int x)
{
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        x /= 10;
        cnt++;
    }
    cnt--;
    return dfs(cnt, 0, 0);
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    int t;
    while (cin >> t)
    {
        int n, m;
        for (int i = 0; i < t; i++)
        {
            cin >> n >> m;
            cout << calc(m) - calc(n - 1) << endl;
        }
    }
}