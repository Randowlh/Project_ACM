#include<cstdio>
#include<iostream>
using namespace std;
int v[1000];
int w[1000];
int dp[1001][1001];
int  t,n;
int main(){
    scanf("%d%d",&t,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    for(int i=1;i<=n;i++)
    for(int j=t;j>=0;j--){
        if(j>=w[i]){
            dp[i][j]=max(dp[i-1][j] ,dp[i-1][j-w[i]]+v[i]);
        }else{
            dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
    
    for(int j=0;j<=t;j++){
        printf("%d ",dp[i][j]);
    }
    printf("\n");}
    printf("%d\n",dp[n][t]);
    return 0;
}