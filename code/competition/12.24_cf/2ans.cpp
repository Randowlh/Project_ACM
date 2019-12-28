#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[200010];
int date[200010];
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&date[i]);
        }
        sort(date+1,date+n+1);
        for(int i=1;i<=n;i++){
            if(i<k){
                dp[i]=dp[i-1]+date[i];
            }else dp[i]=min(dp[i-1]+date[i],dp[i-k]+date[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(p>=dp[i])
            ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}