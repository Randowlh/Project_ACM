#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[110][110];
signed main(){
    string tmp;
    memset(dp,63,sizeof(dp));
    cin>>tmp;
    for(int i=0;i<=tmp.size();i++)
        dp[i][i]=1;
    for(int len=1;len<=tmp.size();len++){
        for(int i=0;i+len<tmp.size();i++){
            if(tmp[i]==tmp[i+len]){
                dp[i][i+len]=min(dp[i+1][i+len],dp[i][i+len-1]);
                continue;
            }
            for(int k=i;k<i+len;k++){
                dp[i][i+len]=min(dp[i][i+len],dp[i][k]+dp[k+1][i+len]);
            }
        }
    }
    cout<<dp[0][tmp.size()-1]<<endl;
}