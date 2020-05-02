#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int a = 0, b = 0;
    int n;
    cin >> n;
    a += 1 << n;
    for (int i = n - 1; i >= n / 2; i--)
    {
        b += 1 << i;
    }
    for (int i = n / 2 - 1; i > 0; i--)
        a += 1 << i;
    cout << abs(a - b) << endl;
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