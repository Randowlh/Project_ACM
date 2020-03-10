#include <bits/stdc++.h>
using namespace std;
int mp[110][110];
int dp[110][110];
int mod = 10000;
int main()
{
    int t;
    cin >> t;
    for (int w = 0; w < t; w++)
    {
        int n, m;
        while (cin >> n >> m)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cin >> mp[i][j];
                }
            }
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int e = mp[i][j];
                    for (int k = 0; k + i < n && k <= e; k++)
                    {
                        for (int q = 0; q + j < m && q + k <= e; q++)
                        {
                            if (k != 0 || q != 0)
                                dp[i + k][j + q] = (dp[i + k][j + q] + dp[i][j]) % mod;
                        }
                    }
                }
            }
            cout << dp[n - 1][m - 1] << endl;
        }
    }
    return 0;
}