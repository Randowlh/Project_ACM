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
    for (int i = 1; i < b; i++)
    {
        int ta = a;
        int mi = inf;
        int mx = 0;
        while (ta != 0)
        {
            mi = min(mi, ta % 10);
            mx = max(mx, ta % 10);
            ta /= 10;
        }
        if (mi * mx == 0)
        {
            cout << a << endl;
            return;
        }
        a += mi * mx;
    }
    cout << a << endl;
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