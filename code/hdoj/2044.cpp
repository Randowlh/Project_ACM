#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long  dp[10000];
int main(){
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<100;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    long long n;
    //dp[1]=1;
    while(cin>>n){
        int tmp1,tmp2,res;
        for(int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            if(tmp1>=tmp2)
            res=0;
            else
             res=tmp2-tmp1+1;
            cout<<dp[res]<<endl;
        }
    }
    return 0;
}