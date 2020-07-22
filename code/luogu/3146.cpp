#include<bits/stdc++.h>
using namespace std;
int dp[300][300];
int date[300];
int n;
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> date[i],dp[i][i]=date[i];
    for (int len = 1; len <n;len++)
        for (int i = 1; i + len <= n;i++)
            for (int k = 1; k < i + len;k++)
                if (dp[i][k] == dp[k + 1][i +len])
                    dp[i][i+len] = max(dp[i][i+len], dp[i][k] + 1);
    int ans = 0;
    for (int i = 1; i <= n;i++)
        for (int j = i; j <= n;j++)
            ans = max(dp[i][j], ans);
    cout << ans << endl;
}