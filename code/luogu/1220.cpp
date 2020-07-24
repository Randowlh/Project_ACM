#include<bits/stdc++.h>
using namespace std;
int dp[55][55][2];
int n, c;
pair<int, int> d[100];
int pr[100];
int calc(int t,int i,int j){
    return t * (pr[n] - (pr[j] - pr[i - 1]));
}
int main(){
   // freopen("in.txt", "r", stdin);
    cin >> n >> c;
    for (int i = 1; i <= n;i++)
        cin>>d[i].first>>d[i].second;
    for (int i = 1; i <= n;i++)
        pr[i] = pr[i - 1] + d[i].second;
        memset(dp, 63, sizeof(dp));
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int len = 1; len < n;len++){
        for (int i = 1; i + len <= n;i++){
            dp[i][i + len][1] = min(dp[i][i + len - 1][1] + calc(d[i + len].first - d[i + len - 1].first, i, i + len - 1), dp[i][i + len - 1][0] + calc(d[i + len].first - d[i].first, i, i + len-1));
            dp[i][i + len][0] = min(dp[i + 1][i + len][1] + calc(d[i + len].first - d[i].first, i + 1, i + len), dp[i + 1][i + len][0] + calc(d[i + 1].first - d[i].first, i + 1, i + len));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
}