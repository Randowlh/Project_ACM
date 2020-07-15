#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[10][5100];
int ddp[10][5100];
int lim;
int disg[10];
int cnt = 0;
int dfs(int pos, int now, int flag)
{
    if (pos < 0)
        return now <= lim;
    if (now > lim)
        return 0;
    if (flag && dp[pos][lim - now] != -1)
        return dp[pos][lim - now];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
        ans += dfs(pos - 1, now + i * (1 << pos), flag || i < num);
    if (flag)
    {
        // ddp[pos][now] = cnt;
        dp[pos][lim - now] = ans;
    }
    return ans;
}
// int dfs(int pos, int nw, int lm)
// {
//     if (pos < 0)
//         return nw <= lim;
//     if (nw > lim)
//         return 0;
//     if (!lm && dp[pos][lim - nw] > -1)
//         return dp[pos][lim - nw];
//     int i, k = lm ? disg[pos] : 9, s = 0;
//     for (i = 0; i <= k; i++)
//         s += dfs(pos - 1, nw + i * (1 << pos), lm && i == disg[pos]);
//     if (!lm)
//         return dp[pos][lim - nw] = s;
//     return s;
// }
inline int work(int x)
{
    int cnt = 0;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    cnt--;
    return dfs(cnt, 0, 0);
}
int calc(int x)
{
    int F;
    int k = 0;
    for (F = 0; x > 0; k++, x /= 10)
        F += x % 10 * (1 << k);
    return F;
}
inline int read()
{
    int x = 0;
    char c = getchar();
    bool p = 0;
    for (; c < '0' || c > '9'; c = getchar())
        p |= c == '-';
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return p ? -x : x;
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    memset(dp, -1, sizeof dp);
    while (t--)
    {
        cnt++;
        int n, m;
        n = read();
        m = read();
        lim = calc(n);
        printf("Case #%d: %d\n", cnt, work(m));
    }
    return 0;
}