#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x7FFFFFFF;
int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(true){
        cin>>n;
        if(n==0)
            break;
        ll dp[1010];
        int date[1010];
        for(int i=1;i<=n;i++){
            scanf("%d",&date[i]);
        }
        for(int i=0;i<=n+1;i++){
            dp[i]=0;
        }
        date[0]=-inf;
       // dp[]=0;
       date[n+1]=inf;
        dp[0]=0;
        for(int i=1;i<=n+1;i++){
            for(int j=0;j<i;j++){
                 if(date[i]>date[j]){
                     if(i!=n+1)
                     dp[i]=max(dp[i],dp[j]+date[i]);
                     else 
                     dp[i]=max(dp[i],dp[j]);
                 }
            }
        }
        cout<<dp[n+1]<<endl;
    }
    return 0;
}
