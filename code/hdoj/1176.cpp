#include <bits/stdc++.h>
using namespace std;
int dp[100010][11];
int n;
int main()
{
    // freopen("in.txt", "r", stdin);
    while (cin >> n, n)
    {
        memset(dp, 0, sizeof(dp));
        int a, b;
        int ma = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> b >> a;
            dp[a][b]++;
            ma = max(ma, a);
        }
        for (int i = ma - 1; i >= 0; i--)
        {
            for (int j = 1; j < 10; j++)
            {
                dp[i][j] = max(dp[i + 1][j], max(dp[i + 1][j - 1], dp[i + 1][j + 1])) + dp[i][j];
            }
            dp[i][10] = max(dp[i + 1][10], dp[i + 1][9]) + dp[i][10];
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]) + dp[i][0];
        }
        cout << dp[0][5] << endl;
    }
}