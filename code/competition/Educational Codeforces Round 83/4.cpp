#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = 998244353;
ll F[200100], G[200100];
ll pows(int i, ll a)
{
    ll ans = 1;
    ll tmp = 1;
    ll k = i;
    while (a)
    {
        if (a & 1)
        {
            ans = (ans * k) % mod;
        }
        a >>= 1;
        k = (k * k) % mod;
    }
    return ans;
}
void init()
{
    F[0] = 1;
    G[0] = 1;
    for (int i = 1; i <= 200010; i++)
    {
        F[i] = F[i - 1] * i % mod;
        G[i] = G[i - 1] * pows(i, mod - 2) % mod;
    }
    return;
}
ll C(ll n, ll m)
{
    return F[n] * G[m] % mod * G[n - m] % mod;
}
void work()
{
    init();
    int n, m;
    cin >> n >> m;
    if (m < n - 1)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = n - 2; i < m; i++)
    {
        ans = (C(i, n - 2) + ans) % mod;
    }
    ans = (ans * (n - 2)) % mod * pows(2, n - 3) % mod;
    cout << ans << endl;
    return;
}
int main()
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