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
    if (a <= b)
    {
        cout << 1 << endl;
        return;
    }
    int ma = 1;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (i <= b)
                ma = max(ma, i);
            if (a / i <= b)
                ma = max(ma, a / i);
        }
    }
    cout << a / ma << endl;
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