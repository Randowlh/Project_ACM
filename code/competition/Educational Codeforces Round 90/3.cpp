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
int dp[1100000];
void work()
{
    string tmp;
    cin >> tmp;
    int now = 0;
    for (int i = 0; i <= tmp.size(); i++)
        dp[i] = -1;
    int mx = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        //cout << "now=" << now << endl;
        if (tmp[i] == '-')
            now--;
        else
            now++;
        if (now < 0 && dp[-now] == -1)
        {
            dp[-now] = i + 1;
            mx = max(-now, mx);
        }
    }
    int ans = 0;
    for (int i = 1; i <= mx; i++)
    {
        if (dp[i] != -1)
            ans += dp[i];
    }
    ans += tmp.size();
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}