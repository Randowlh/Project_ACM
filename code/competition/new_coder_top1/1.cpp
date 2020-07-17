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

int n, m;
inline bool ck(int x, int m)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans == m;
}
void work()
{
    //    int n, m;
    cin >> n >> m;
    int s = pow(10, n - 1);
    int e = pow(10, n) - 1;
    int ans = 0;
    for (int i = s; i <= e; i++)
    {
        if (ck(i, m))
        {
            ans += i;
        }
    }
    cout << ans << endl;
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