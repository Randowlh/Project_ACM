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
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    int ta = a;
    int cnt = 0;
    while (a < b)
    {
        a <<= 1;
        cnt++;
        if (a == b)
        {
            cout << cnt / 3 + (cnt % 3 > 0) << endl;
            return;
        }
    }
    a = ta;
    cnt = 0;
    while (a > b && a % 2 == 0)
    {
        a >>= 1;
        cnt++;
        if (a == b)
        {
            cout << cnt / 3 + (cnt % 3 > 0) << endl;
            return;
        }
    }
    cout << -1 << endl;
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