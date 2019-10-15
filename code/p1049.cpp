#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[20010];
int date;
int n;
int v;
int main(){
    cin>>v>>n;
    dp[0]=1;
    for(int i=0;i<n;i++){
        scanf("%d",&date);
        for(int j=v;j>=0;j--){
            if(dp[i]==1){
                dp[i+date]=1;
            }
        }
    }
    for(int i=v;i>=0;i++){
        if(dp[i]==1){
            printf("%d\n",v-i);
            return 0;
        }
    }
    return 0;
}