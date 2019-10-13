#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int w[101][1010];
int v[101][1010];
int tails[101];
int dp[1010];
int m,n;
int main(){
    cin>>m>>n;
    int tmp1,tmp2,tmp3;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
        w[tmp3][tails[tmp3]]=tmp1;
        v[tmp3][tails[tmp3]]=tmp2;
        tails[tmp3]++;
    }
    for(int i=0;i<100;i++){
        if(tails[i]!=0){
        for(int j=m;j>=0;j--){
            for(int k=0;k<tails[i];i++){
                if(j>=w[i][k]){
                dp[j]=max(dp[j],dp[j-w[i][k]]+v[i][k]);
                }
            }
        }
        }
    }
    printf("%d",dp[m]);
    return 0;
    }