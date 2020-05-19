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
    if (a <= b)
    {
        cout << b << endl;
        return;
    }
    if (c <= d)
    {
        cout << -1 << endl;
        return;
    }
    cout << b + ((a - b) / (c - d) + ((a - b) % (c - d) > 0)) * c << endl;
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