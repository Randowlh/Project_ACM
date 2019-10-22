#include<cstdio>
#include<iostream>
using namespace std;
int n,k;
int w[2001];
int dp[2001][2001];   
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<k;j++){
            dp[i][j]=min(dp[i-1][])
        }
    }
}