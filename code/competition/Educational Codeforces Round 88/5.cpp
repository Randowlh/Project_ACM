#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define int long long
const int mod = 998244353;
const double eps = 1e-7;
const int llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int n, k;
int fac[510000];
int pows(int a, int b)
{
    int ans = 1;
    int now = a;
    while (b != 0)
    {
        if (b & 1)
            ans = ans * now % mod;
        now = now * now % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    int now = 2;
    fac[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * now % mod;
        now++;
    }
}
int niYuan(int a)
{
    return pows(a, mod - 2);
}
int C(int a, int b)
{
    if (a == b)
        return 1;
    return fac[a] * niYuan(fac[b]) % mod * niYuan(fac[a - b]) % mod;
}
void work()
{

    cin >> n >> k;
    init();
    if (k > n)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    if (k == 1)
    {
        cout << n << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = n / i - 1;
        if (t < k - 1)
            break;
        ans = (ans + C(t, k - 1)) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}