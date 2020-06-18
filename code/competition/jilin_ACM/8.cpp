#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
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
map<pair<int, int>, int> M;
void calc(int a, int b)
{
    for (int i = a; i <= b; i++)
        for (int j = i; j <= b; j++)
            M[make_pair(i, j)]++;
}
void work()
{
    int n;
    cin >> n;
    int ans = 0;
    int tmp;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    for (int i = 1; i <= n; ++i)
    {
        tmp += a[i - 1] * i;
        tmp %= mod;
        ans += b[i - 1] * tmp % mod * (n - i + 1);
        ans %= mod;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     ans = ((a[i - 1] * i) % mod * ((b[i - 1] * (n - i + 1) )% mod + ans) % mod;
    // }
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