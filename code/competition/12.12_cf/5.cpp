#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
int dp[200010];
int date[200010];
int book[200010];
//int st[200010];
int n;
int  dfs(int pos,int flag){
    if(dp[pos]!=0&&dp[pos]!=-1){
        return dp[pos];
    }
    int fl=inf;
    if(pos-date[pos]>=0&&book[pos-date[pos]]==0){
        if(date[pos-date[pos]]%2==flag){
            fl=1;
        }
        else{
            book[pos-date[pos]]=1;
            int tmp=dfs(pos-date[pos],flag)+1;
            if(tmp!=0)
           fl=min(fl,tmp);
           book[pos-date[pos]]=0;
        }
    }
    if(pos+date[pos]<n&&book[pos+date[pos]]==0){
        if(date[pos+date[pos]]%2==flag){
            fl=1;
        }
        else{
            book[pos+date[pos]]=1;
           int tmp=dfs(pos+date[pos],flag)+1;
            if(tmp!=0)
           fl=min(fl,tmp);
            book[pos+date[pos]]=0;
        }
    }
    if(fl==inf){
        fl=-1;
    }
    dp[pos]=fl;
    return fl;
}
int main(){
    //int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
        dp[i]=0;
    }
    for(int i=0;i<n;i++){
        int fl=1;
        if(date[i]%2!=0)
        fl=0;
        book[i]=1;
        dp[i]=dfs(i,fl);
        book[i]=0;
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",dp[i]);
    }
    printf("%d\n",dp[n-1]);
    return 0;
}