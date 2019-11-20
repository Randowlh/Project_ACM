#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int x;
    int r;
    int q;
    bool operator<(node a){
        return this->q<a.q;
    }
}date[100];
int dp[100010];
int n,m;
//int s[100];
//int x[100];
//int qia[100];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>date[i].x>>date[i].r;
        date[i].q=date[i].x-date[i].r;
    }
    sort(date,date+n);
    memset(dp,1<<29,sizeof(dp));  
    dp[m+1]=0;
    for(int i=m;i>=0;i--){
        for(int j=0;j<n;j++){
            if(x[i]<)
        }
    }
    
}