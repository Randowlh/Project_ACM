#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[50][50];
int n,m;
int date[50];
int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>date[i];
        }
        sort(date,date+n,greater<int>());
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                dp[i][j+1]=max(dp[i-1][j-1],0)
            }
        }
    }
}