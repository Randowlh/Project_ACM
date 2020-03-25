#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
inline ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    ll tmp = a;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = ans * tmp % mod;
        }
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll ans = 0;
        if (n - i >= 2)
        {
            ans += 81 * fast_pow(10, n - i - 2) % mod * (n - i - 1) % mod;
            ans += 18 * fast_pow(10, n - i - 1) % mod;
            ans %= mod;
        }
        else if (n - i >= 1)
        {
            ans += 18 * fast_pow(10, n - i - 1) % mod;
        }
        else
        {
            ans = 1;
        }
        cout << ans * 10 % mod << ' ';
    }
    cout << endl;
}