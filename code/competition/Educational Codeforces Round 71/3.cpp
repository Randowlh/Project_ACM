#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const ll llinf = 4223372036854775807;
const double eps = 1e-7;
int dp[2001000][2];
void work()
{
    int n, a, b;
    string tmp1, tmp;
    tmp1.push_back('s');
    cin >> n >> a >> b;
    cin >> tmp;
    tmp1 += tmp;
    dp[0][0] = b;
    dp[0][1] = llinf;
    for (int i = 1; i <= n; i++)
    {
        if (tmp1[i] == '0')
        {
            dp[i][0] = min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a) + b;
            dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + 2 * b;
        }
        else
        {
            dp[i][0] = llinf;
            dp[i][1] = dp[i - 1][1] + a + 2 * b;
        }
    }
    cout << dp[n][0] << endl;
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