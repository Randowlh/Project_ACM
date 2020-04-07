#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int d, m;
    cin >> d >> m;
    int ans = 1;
    int now = 1;
    while (now <= d)
    {
        ans = ans * (min(now, d - now + 1) + 1) % m;
        now <<= 1;
    }
    ans--;
    ans = (ans + m) % m;
    cout << ans << endl;
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