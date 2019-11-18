#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long date[200010];
int n,m;
unsigned long long sum[200010];
unsigned long long dp[200010];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
        //sum[i]=date[i]+sum[i-1];
    }
    sort(date,date+n);
    sum[0]=date[0];
    for(int i=1;i<n;i++){
        sum[i]=date[i]+sum[i-1];
    }
    for(int i=0;i<n;i++){
        if(i<m){
            dp[i]=sum[i];
        }else{
            dp[i]=sum[i]+dp[i-m];
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
    return 0;
    
}