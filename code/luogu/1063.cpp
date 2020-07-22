#include <bits/stdc++.h>
using namespace std;
int dp[210][210];
int hd[210];
int tt[210];
int n;
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> hd[i];
    tt[n] = hd[1];
    for (int i = 1; i < n;i++)
        tt[i] = hd[i + 1];
    for (int i = 1; i <= n;i++)
        hd[i + n] = hd[i], tt[i + n] = tt[i];
    for (int len = 1; len < n;len++)
        for (int i = 1; i + len <= n * 2;i++)
            for (int k = i; k < i + len;k++)
                dp[i][i + len] = max(dp[i][i + len], dp[i][k] + dp[k + 1][i + len] + hd[i] * hd[k + 1] * tt[i + len]);
    int ans = 0;
    for (int i = 1; i <= n;i++)
        ans = max(ans, dp[i][i + n - 1]);
    cout << ans << endl;
}