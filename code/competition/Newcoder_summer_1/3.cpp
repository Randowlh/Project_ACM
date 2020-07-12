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
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
char mp[100][100];
void work()
{
    int n, m;
    while (scanf("%lld %lld", &n, &m))
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        }
}
signed main()
{
    //  std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}