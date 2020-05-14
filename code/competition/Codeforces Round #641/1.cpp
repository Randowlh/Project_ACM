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
    int n, k;
    cin >> n >> k;
    int f = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f = i;
            break;
        }
    }
    if (f == 0)
        f = n;
    int ans = 0;
    if (k == 1)
    {
        cout << f + n << endl;
    }
    else
    {
        cout << f + n + (k - 1) * 2 << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}