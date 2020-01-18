#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
const int mod=1000000007;
void work(){
    ll dp[31][4010];
    ll n,m;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    dp[1][i]=1;
    for(int i=2;i<=n*2;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=0;
            for(int k=1;k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans=(dp[n*2][i]+ans)%mod;
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}