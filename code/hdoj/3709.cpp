#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int dp[20][20][2000];
int disg[20];
int dfs(int pos, int fix, int sum, int flag)
{
    if (pos == 0)
        return sum == 0;
    if (sum < 0)
        return 0;
    int ans = 0;
    int num = flag ? 9 : disg[pos];
    if (flag && dp[pos][fix][sum] != -1)
        return dp[pos][fix][sum];
    for (int i = 0; i <= num; i++)
        ans += dfs(pos - 1, fix, sum + (pos - fix) * i, flag || i < num);
    if (flag)
        dp[pos][fix][sum] = ans;
    return ans;
}

int work(int x)
{
    if (x < 0)
        return 0;
    int ans = 0;
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        x /= 10;
        cnt++;
    }
    cnt--;
    for (int i = 0; i <= cnt; i++)
        ans += dfs(cnt, i, 0, 0);
    ans -= cnt;
    return ans;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        cout << work(y) - work(x - 1) << endl;
    }
    return 0;
}