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
void work()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = c; i <= d; i++)
    {
        ans += max(0LL, min((b - a + 1) * (c - b + 1) - max(0LL, max(0LL, (i - b - a)) * (i - b - a + 1) / 2), (b + c - i) * (b + c - i + 1) / 2));
    }
    cout << ans << endl;
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