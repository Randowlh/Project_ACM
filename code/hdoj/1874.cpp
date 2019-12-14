#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
int dis[1000];
int flag[1000];
int map[300][300];
int main(){
    int m,n;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                map[i][j]=inf;
            }
        int s,e,v;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&s,&e,&v);
            map[s][e]=min(v,map[s][e]);
            map[e][s]=min(v,map[e][s]);
        }
        scanf("%d%d",&s,&e);
        for(int i=0;i<=n;i++){
            dis[i]=inf;
            flag[i]=1;
        }
        dis[s]=0;
        flag[s]=0;
        while(s!=e){
            int mi=inf;
            int next=-1;
            for(int i=0;i<n;i++){
                if(map[s][i]!=inf)
                dis[i]=min(dis[i],dis[s]+map[s][i]);
                 if(flag[i]==1&&dis[i]<mi){
                     mi=dis[i];
                     next=i;
                 }
            }
            if(mi==inf)break;
            s=next;
            flag[s]=0;
        }
        if(dis[e]==inf) cout<<-1<<endl;
        else printf("%d\n",dis[e]);
    }
    return 0;
}