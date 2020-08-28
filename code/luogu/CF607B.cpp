#include <bits/stdc++.h>
using namespace std;
int date[505];
int dp[505][505];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dp, 63, sizeof(dp));
    for(int i=1;i<=n;i++)
        cin>>date[i];
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        if(i!=n)
        dp[i][i+1]=1+(date[i]!=date[i+1]);
    }
    for(int len=2;len<=n;len++)
        for(int i=1;i+len<=n;i++){
            if(date[i]==date[i+len])
                dp[i][i+len]=dp[i+1][i+len-1];
            for(int k=i;k<i+len;k++)
                    dp[i][i+len]=min(dp[i][i+len],dp[k+1][i+len]+dp[i][k]);
            }
    cout<<dp[1][n]<<endl;
}