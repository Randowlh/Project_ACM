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
int dp[2510000];
int dis[2510000];
void work()
{
    int n
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    dp[0] = 0;
    int mv = -a[1];
    dp[1] = 1 << 30;
    for (int i = 2; i <= n / 2; i++)
    {
        dp[i] = mv + a[2 * i];
        mv = min(mv, dp[i - 1] - a[2 * i - 1]);
        }
        printf("%d\n",2*dp[n/2]);
}
signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
  freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}