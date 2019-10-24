#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int dp[100];
int main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    for(int i=5;i<100;i++){
        dp[i]=dp[i-1]+dp[i-3];
    }
    int n;
    while(true){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}