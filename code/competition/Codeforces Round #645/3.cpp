#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int x, y;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void ex_gcd(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        ex_gcd(b, a % b);
        long t = x;
        x = y;
        y = t - (a / b) * y;
    }
}
int fac(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++)
        ans *= i;
    return ans;
}
int c(int b, int a)
{
    return fac(b) / (fac(a) * fac(a - b));
}
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 -= x1;
    y2 -= y1;
    cout << 1 + (x2) * (y2) << endl;
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