#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int inf =0x7FFFFFFF;
int map[1010][1010];
int dis[1010];
int flag[1010];
int main(){
    int s,t,d;
    while(cin>>t>>s>>d){
        int b,e,v;
        int n=max(t,max(s,d));
        for(int i=0;i<n+100;i++)
            for(int j=0;j<n+100;j++)
                map[i][j]=inf;
        for(int i=0;i<n+100;i++){
            dis[i]=inf;
        }
        for(int i=0;i<t;i++){
        scanf("%d%d%d",&b,&e,&v);
        map[b][e]=min(map[b][e],v);
        map[e][b]=map[b][e]; 
       }
       for(int i=0;i<s;i++){
           scanf("%d",&e);
           map[0][e]=0; 
       }
       while(true){
           
       }
       for(int i)
    }
}