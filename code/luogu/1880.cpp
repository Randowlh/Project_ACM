#include <bits/stdc++.h>
using namespace std;
int dp[210][210],dps[210][210];
int date[210];
int n;
int pre[210];
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> date[i], date[n + i] = date[i];
    for (int i = 1; i <= n * 2;i++)
        pre[i] = pre[i - 1] + date[i];
    for (int len = 1; len < n;len++)
        for (int i = 1; i + len <= n * 2; i++){
            dps[i][i + len] = 0x7FFFFFFF;
            for (int k = i; k < i + len; k++)
            {
                dps[i][i + len] = min(dps[i][i + len], dps[i][k] + dps[k + 1][i + len] + (pre[i + len] - pre[i - 1]));  
                dp[i][i + len] = max(dp[i][i + len], dp[i][k] + dp[k + 1][i + len] + (pre[i + len] - pre[i - 1]));
            }
        }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n;i++)
        ans = min(dps[i][i + n-1],ans);
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n;i++)
    ans=max(dp[i][i + n-1],ans);
    cout << ans << endl;
}