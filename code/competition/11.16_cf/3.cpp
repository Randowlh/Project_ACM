#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long date[200010];
int n,m;
unsigned long long dp[200010];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
        if(i<m){
            dp[i]=dp[i-1]+date[i];
        }else{
            dp[i]=dp[i-1]+
        }
    }
    
}