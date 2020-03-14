#include <bits/stdc++.h>
using namespace std;
int main()
{
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        int mp[110][110];
        memset(mp, -1, sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> mp[i][j];
            }
        }
        int dp[110][110];
        dp[0][0] = mp[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = 0;
                if ((j - 1) >= 0)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (j < i)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                dp[i][j] += mp[i][j];
            }
        }
        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            ma = max(ma, dp[n - 1][i]);
        }
        cout << ma << endl;
    }
}