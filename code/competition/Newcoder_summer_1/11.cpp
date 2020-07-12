#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
struct node
{
    int zi, mu;
    node(int a = 0, int b = 0) : zi(a), mu(b) {}
    node operator+(node a)
    {
        node ans;
        int aa = lcm(mu, a.mu);
        ans.zi = zi * (aa / mu) + a.zi * (aa / a.mu);
        ans.mu = aa;
        int tt = gcd(abs(ans.zi), ans.mu);
        ans.zi /= tt;
        ans.mu /= tt;
        return ans;
    }
};
int C(int n, int m)
{
    int chu = 1;
    for (int i = 1; i <= m; i++)
    {
        chu *= i;
    }
    int che = 1;
    for (int i = n; i > n - m; i--)
    {
        che *= i;
    }
    return che / chu;
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
    for (int q = 1; q < 10; q++)
    {
        node ans(0, 1);
        for (int i = 1; i <= q; i++)
        {
            node tt;
            tt.mu = q + i;
            tt.zi = C(q, i);
            if (i % 2 == 0)
                tt.zi = -tt.zi;
            cout << tt.zi << "/" << tt.mu << endl;
            ans = ans + tt;
        }
        cout << "q=" << q << endl;
        cout << ans.mu << ' ' << ans.zi << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}