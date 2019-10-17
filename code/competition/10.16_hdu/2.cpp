#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int t;
int dp[1000010];
int w[2],v[2];
int main(){
    cin>>t;
    double a,b,c,d;
    int m;
    for(int k=0;k<t;k++){
        cin>>m>>w[0]>>v[0]>>w[1]>>v[1];
        for(int i=0;i<=m;i++){
            dp[i]=0;
        }        
        for(int i=0;i<2;i++){
            for(int j=0;j<=m;j++){
            if(j>=w[i]){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[m]);
    }
    return 0;
}