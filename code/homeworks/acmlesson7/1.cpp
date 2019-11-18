#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int flag[10000];
int date[10000];
int n,a,b;
int ans=1<<29;
void dfs(int now,int time){
    if(now==b){
        ans=min(ans,time);
        return;
    }
    if(time>=ans){
        return;
    }
    if(now-date[now]>0&&flag[now-date[now]]==0){
        flag[now-date[now]]=1;
        dfs(now-date[now],time+1);
        flag[now-date[now]]=0;
    }
    if(now+date[now]<=n&&flag[now+date[now]]==0){
        flag[now+date[now]]=1;
        dfs(now+date[now],time+1);
        flag[now+date[now]]=0;
    }
    return ;
}
int main(){
   // double x,*p=&x;
    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            cin>>date[i];
        }
    memset(flag,0,sizeof(flag));
    ans=9999999;
    flag[a]=1;
    dfs(a,0);
    if(ans==9999999){
        ans=-1;
    }
    printf("%d\n",ans);
    }
    return 0;
}