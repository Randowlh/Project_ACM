#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = 998244353;
const double eps = 1e-7;
int dp[101000];
void work()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 6;
    for (int j = 4; j <= n; j++)
    {
        int tol = 0;
        for (int i = 1; i * i <= j; i++)
        {
            if (j % i == 0)
            {
                if (i * i != j)
                {
                    if (i & 1)
                        tol = (tol + 1) % mod;
                    else
                        tol = (tol + i) % mod;
                    if ((j / i) & 1)
                        tol = (tol + 1) % mod;
                    else
                        tol = (tol + j / i) % mod;
                }
                else if (i & 1)
                    tol = (tol + 1) % mod;
                else
                    tol = (tol + i) % mod;
            }
        }
        dp[j] = (tol + dp[j - 1]) % mod;
    }
    cout << dp[n] << endl;
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