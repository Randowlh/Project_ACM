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
int dp[110000];
void work()
{
    int n;
    while (cin >> n)
    {
        int tmp;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        if (n == 1)
        {
            cout << v[0] << endl;
            return;
        }
        dp[0] = v[0];
        dp[1] = max(v[0], v[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + max(0LL, v[i]));
        }
        cout << dp[n - 1] << endl;
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