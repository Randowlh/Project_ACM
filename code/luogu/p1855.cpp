#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[210][210];
int t[210];
int w[210];
int n;
int mon,time;
int main(){
    cin>>n>>mon>>time;
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&t[i]);
    }
    for(int i=0;i<n;i++){
        for(int k=mon;k>=0;k--)
            for(int j=time;j>=0;j--){
                if(k>=w[i]&&j>=t[i]){
                    dp[k][j]=max(dp[k][j],dp[k-w[i]][j-t[i]]+1);
                }
            }
    }
    printf("%d\n",dp[mon][time]);
    return 0;

    
}