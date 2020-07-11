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
int dp[20][8][8][3];
int disg[20];
int dfs(int pos, int mod, int mod2, int staus, int flag)
{
    if (pos == 0)
        return staus || mod == 0 || mod2 == 0;
    if (flag && dp[pos][mod][mod2][staus] != -1)
        return dp[pos][mod][mod2][staus];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        int f = i == 7;
        ans += dfs(pos - 1, (mod + i) % 7, (mod2 * 10 + i) % 7, f || staus, flag || i < num);
    }
    if (flag)
        dp[pos][mod][mod2][staus] = ans;
    return ans;
}
int work(int x)
{
    if (x < 0)
        return 0;
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    cnt--;
    return dfs(cnt, 0, 0, 0, 0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int x, y;
        cin >> x >> y;
        cout << work(y) - work(x - 1) << endl;
    }
    return 0;
}