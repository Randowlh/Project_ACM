#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int dp[2][300010];
int mp[2][300010];
void work(){
    int n,q;
    cin>>n>>q;
     dp[0][1]=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&mp[0][i],&mp[1][i]);
        dp[0][i]=inf;
        dp[1][i]=inf;
    }
    if((dp[0][1]+1/mp[1][1])%2==1){
       dp[1][1]=mp[1][1]*(((dp[0][1]+1)/mp[1][1])+1);
    }else dp[1][1]=dp[0][1]+1;
    for(int i=0;i<2;i++){
        for(int j=2;j<=n;j++){
            if(i==0){
                if(((dp[0][j-1]+1)/mp[0][j])%2==1){
                    dp[0][j]=min(dp[0][j],mp[0][j]*((dp[0][j-1]+1)/mp[0][j]+1));
                }else dp[0][j]=min(dp[0][j],dp[0][j-1]+1);
                /////////////////////////////////
                 if(((dp[1][j]+1)/mp[0][j])%2==1){
                    dp[0][j]=min(dp[0][j],mp[0][j]*((dp[1][j]+1)/mp[0][j]+1));
                }else dp[0][j]=min(dp[0][j],dp[1][j]+1);
            }else{
                if(((dp[1][j-1]+1)/mp[1][j])%2==1){
                    dp[1][j]=min(dp[1][j],mp[1][j]*((dp[1][j-1]+1)/mp[1][j]+1));
                }else dp[1][j]=min(dp[1][j],dp[1][j-1]+1);
                /////////////////////////////////
                 if(((dp[0][j]+1)/mp[1][j])%2==1){
                    dp[1][j]=min(dp[1][j],mp[1][j]*((dp[0][j]+1)/mp[1][j]+1));
                }else dp[1][j]=min(dp[1][j],dp[1][j]+1);
            }
        }
    }
    if(dp[1][n]>=q){
        cout<<"No"<<endl;
    }else 
    cout<<"Yes"<<endl;
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