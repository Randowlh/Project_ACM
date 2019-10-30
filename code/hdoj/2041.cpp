#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[10000];
int main(){
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<100;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int n;
    dp[1]=0;
    while(cin>>n){
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            cout<<dp[tmp]<<endl;
        }
    }
    return 0;
}