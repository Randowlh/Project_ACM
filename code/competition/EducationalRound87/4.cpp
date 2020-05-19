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
    long double pi = acos(-1);
    long double n;
    int t;
    cin >> t;
    n = t;
    n *= 2;
    long double tol = pi * (n - 2);
    tol /= n;
    tol = pi - tol;
    long double ans = 0, now = 0;
    now += tol / 2;
    for (int i = 1; i < t; i++)
    {
        ans += 1 * sin(now);
        now += tol;
    }
    ans += 1 * sin(now);
    cout << fixed << setprecision(9) << ans << endl;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}