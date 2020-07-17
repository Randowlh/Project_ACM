#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int mp[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = mp[n][i];
    }
    for (int i = n - 1; i >= 1; i--)
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
            dp[i][j] += mp[i][j];
        }
    cout << dp[1][1] << endl;
}