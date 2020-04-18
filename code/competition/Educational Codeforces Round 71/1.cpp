#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int ans = 0;
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    if (h > c)
    {
        ans = min(b / 2, p);
        b -= ans * 2;
        ans *= h;
        ans += c * min(b / 2, f);
    }
    else
    {
        ans = min(b / 2, f);
        b -= ans * 2;
        ans *= c;
        ans += h * min(b / 2, p);
    }
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