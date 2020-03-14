#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int dp[30][30];
        int mp[30][30];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                cin >> mp[i][j];
        for (int i = 0; i < k; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                int mi = 99999;
                for (int q = 0; q < k; q++)
                {
                    mi = min(mi, dp[i - 1][q] + abs(mp[i][j] - mp[i - 1][q]));
                }
                dp[i][j] = mi;
            }
        }
        int ans = 999999;
        for (int i = 0; i < k; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}