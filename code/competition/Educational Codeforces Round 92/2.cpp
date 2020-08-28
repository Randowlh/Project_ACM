#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template <class T>
inline void MAX(T &x, T y)
{
    if (y > x)
        x = y;
}
template <class T>
inline void MIN(T &x, T y)
{
    if (y < x)
        x = y;
}
template <class T>
inline void rd(T &x)
{
    x = 0;
    char o, f = 1;
    while (o = getchar(), o < 48)
        if (o == 45)
            f = -f;
    do
        x = (x << 3) + (x << 1) + (o ^ 48);
    while (o = getchar(), o > 47);
    x *= f;
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm = 1;
int sum[110000];
int a[110000];
int v[110000];
void work()
{
    int n, k, z;
    cin >> n >> k >> z;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        v[i] = 0;
    }
    for (int i = 2; i <= n; ++i)
        v[i] = max(v[i - 1], a[i] + a[i - 1]);
    k++;
    int ans = 0;
    for (int i = 0; i <= z; ++i)
    {
        int cnt = sum[k];
        if (k - 2 * i >= 2)
        {
            int s1 = sum[k - 2 * i] + i * v[k - 2 * i];
            cnt = max(s1, cnt);
        }
        if (i && k - 2 * i + 1 >= 2)
        {
            int g = k - 2 * i + 1;
            int s2 = sum[g] + (i - 1) * v[g] + a[g - 1];
            cnt = max(cnt, s2);
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}