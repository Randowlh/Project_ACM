#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int dpx[110000];
int dpl[110000];
int dp[110][110];
string tmp;
int dfs(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    int ma = 0;
    int tl = 0;
    int tr = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        tl = max(0LL, dpx[i] - 2 - l);
        tr = max(0LL, dpl[i] - 1 - r);
        ma = max(ma, min(max(0LL, dpx[i] - 2 - l), max(0LL, dpl[i] - 1 - r)));
    }
    if (ma == 0)
    {
        dp[l][r] = 0;
        return 0;
    }
    cout << ma << endl;
    int ans = ma;
    int mi = inf;
    cout << l << ' ' << r << ' ' << ma << endl;
    if (tl != 0)
    {
        mi = min(dfs(l + tl, r), mi);
    }
    if (tr != 0)
    {
        mi = min(dfs(l, r + tr), mi);
    }
    ans += mi;
    dp[l][r] = ans;
    return ans;
}
void work()
{
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++)
        for (int j = 0; j < tmp.size(); j++)
            dp[i][j] = -1;
    dpx[0] = (tmp[0] == 'x');
    dpl[tmp.size() - 1] = (tmp[tmp.size() - 1] == 'l');
    for (int i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] == 'x')
            dpx[i] = dpx[i - 1] + 1;
        else
            dpx[i] = dpx[i - 1];
    }
    for (int i = tmp.size() - 2; i >= 0; i--)
    {
        if (tmp[i] == 'l')
            dpl[i] = dpl[i + 1] + 1;
        else
            dpl[i] = dpl[i + 1];
    }
    int ans = 0;
    int l = 0;
    int r = 0;
    ans = dfs(l, r);
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("a.in", "r", stdin);
    //  freopen("a.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}