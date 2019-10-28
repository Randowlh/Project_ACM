#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
 int st;
 int et;
 bool operator<(const node a){
     if(this->et==a.et){
         return this->st<a.st;
     }else
     return this->et<a.et;
 }    
} date[10000];
int f[10000];
int dp[10000];
int fr(int n){
    if(f[n]!=-1){
        return f[n];
    }else{
        for(int i=n-1;i>0;i--){
            if(date[i].et<=date[n].st){
                f[n]=i;
                return f[n];
            }
        }
        f[n]=0;
        return f[n];
    }
}
int main(){
    int n;
    while(true){
        cin>>n;
        memset(f,-1,sizeof(int)*(n+2));
        if(n==0){
            break;
        }
        for(int i=1;i<=n;i++){
            scanf("%d%d",&date[i].st,&date[i].et);
        }
        sort(date,date+n+1);
        dp[1]=1;
        dp[0]=0;
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],dp[fr(i)]+1);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
