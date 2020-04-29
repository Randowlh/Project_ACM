#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a * 2 <= b || (x <= 0 && y >= 0) || (x >= 0 && y <= 0))
    {
        cout << a * (abs(x) + abs(y)) << endl;
    }
    else
    {
        int ans = 0;
        int t = min(abs(x), abs(y));
        ans += t * b;
        if (x > 0)
        {
            x -= t;
            y -= t;
        }
        else
        {
            x += t;
            y += t;
        }
        ans += a * (abs(x) + abs(y));
        cout << ans << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}