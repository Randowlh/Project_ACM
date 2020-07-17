#include <bits/stdc++.h>
using namespace std;
int dp[1010][2010];
int sum[1010];
int mod = 2012;
int main()
{
    string tmp;
    cin >> tmp;
    int now = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '(')
            now++;
        else
            now--;
        if (now < 0)
        {
            cout << 0 << endl;
            return 0;
        }
        sum[i] = now;
    }
    if (sum[tmp.size()])
    {
        cout << 0 << endl;
        return 0;
    }
    int n = tmp.size();
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (tmp[i] == ')')
            for (int j = 1; j <= n; j++)
            {
                if (sum[i] - j >= 0)
                    dp[i][j] = dp[i + 1][j];
                dp[i][j] += dp[i + 1][j - 1];
                dp[i][j] %= mod;
            }
        else
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i + 1][j];
                dp[i][j] += dp[i + 1][j + 1];
                dp[i][j] %= mod;
            }
    }
    cout << dp[0][0] << endl;
}