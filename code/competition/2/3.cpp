#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
long long mod=1000000007;
long long dp[100110];
string tmp;
void calc(){
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<100000;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
       // cout<<dp[i]<<endl;
    }
    return ;
}
int main(){
    calc();
    long long ans=1;
    cin>>tmp;
    int f1=0;
    int f2=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]=='w'||tmp[i]=='m'){
            printf("0\n");
            return 0;
        }else
        if(tmp[i]=='n'){
            f1++;
            ans=dp[f2]*ans%mod;
            f2=0;
        }else if(tmp[i]=='u'){
            f2++;
            ans=dp[f1]*ans%mod;
            f1=0;
        }else {
            ans=dp[f2]*ans%mod;
            ans=dp[f1]*ans%mod;
            f1=0;
            f2=0;
        } 
    }
    ans=dp[f2]*ans%mod;
            ans=dp[f1]*ans%mod;
            f1=0;
            f2=0;
    cout<<ans<<endl;
    return 0;
}