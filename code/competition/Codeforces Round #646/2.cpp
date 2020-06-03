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
int dp0[1100], dp1[1100];
void work()
{
    string tmp;
    cin >> tmp;
    dp0[0] = tmp[0] == '0';
    for (int i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] == '0')
            dp0[i] = dp0[i - 1] + 1;
        else
            dp0[i] = dp0[i - 1];
    }
    dp1[tmp.size() - 1] = (tmp[tmp.size() - 1] == '0');
    for (int i = tmp.size() - 2; i >= 0; i--)
    {
        if (tmp[i] == '0')
            dp1[i] = dp1[i + 1] + 1;
        else
            dp1[i] = dp1[i + 1];
    }
    int ans = inf;
    for (int i = 0; i < tmp.size() - 1; i++)
        ans = min(ans, min(i - dp0[i] + 1, dp0[i]) + min(dp1[i + 1], (int)tmp.size() - dp1[i + 1]));
    cout << ans << endl;
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
        work();
    }
    return 0;
}