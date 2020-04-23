#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n, m;
int ans = 0;
int mp[110][110];
int dp[110][110];
int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    int now = 0;
    int f = 0;
    // cout << x << ' ' << y << ' ' << endl;
    for (int i = x + 1; i <= min(n - 1, x + m); i++)
    {
        if (mp[i][y] > mp[x][y])
            now = max(now, dfs(i, y));
    }
    for (int i = x - 1; i >= max(0LL, x - m); i--)
    {
        if (mp[i][y] > mp[x][y])
            now = max(now, dfs(i, y));
    }
    for (int i = y + 1; i <= min(n - 1, y + m); i++)
    {
        if (mp[x][i] > mp[x][y])
            now = max(now, dfs(x, i));
    }
    for (int i = y - 1; i >= max(0LL, y - m); i--)
    {
        if (mp[x][i] > mp[x][y])
            now = max(now, dfs(x, i));
    }
    dp[x][y] = now + mp[x][y];
    return dp[x][y];
}
void work()
{
    while (cin >> n >> m)
    {
        memset(dp, -1, sizeof dp);
        ans = 0;
        if (n == -1 && m == -1)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mp[i][j];
        ans = dfs(0, 0);
        cout << ans << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}