#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 19650827;
int dp[1100][1100][2];
int date[1100];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> date[i];
    }
    for (int i = 1; i <= n; i++)
        dp[i][i][0] = 1;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len <= n; i++)
        {
            if (date[i] < date[i + 1])
                dp[i][i+len][0] += dp[i + 1][i+len][0];
            if (date[i] < date[i+len])
                dp[i][i+len][0] += dp[i + 1][i+len][1];
            if (date[i+len] > date[i])
                dp[i][i+len][1] += dp[i][i+len - 1][0];
            if (date[i+len] > date[i+len - 1])
                dp[i][i+len][1] += dp[i][i+len - 1][1];
            dp[i][i+len][0] %= mod;
            dp[i][i+len][1] %= mod;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod<<endl;
}