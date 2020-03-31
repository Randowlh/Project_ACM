#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int cl(int k)
{
    int ans = 1;
    while (k != 0)
    {
        k >>= 1;
        ans <<= 1;
    }
    return ans;
}
void work()
{
    int k;
    cin >> k;
    cout << 3 << ' ' << 3 << endl;
    int res = cl(k);
    cout << res + k << ' ' << res << ' ' << res + k << endl;
    cout << k << ' ' << res << ' ' << res << endl;
    cout << res + k << ' ' << res + k << ' ' << k << endl;
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}