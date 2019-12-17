#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
struct node
{
    int po;
    int a,b,c;

}date[6000];
int bl[6000];
int n,m,k;
int  loos[6000];
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&date[i].a,&date[i].b,&date[i].c);
        date[i].po=-1;
    }
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        date[u-1].po=v-1;
    } 
    bl[0]=k;
    int flag=0;
    for(int i=0;i<n;i++){
        if(bl[i]<date[i].a){
            flag=1;
            break;
        }
        bl[i+1]=bl[i]+date[i].b;
    }
    if(flag==1){
        cout<<-1<<endl;
    }
    for(int i=0;i<n;i++){
        bl[i]-=i;
        bl[i]-=date[i].a;
    }
    for(int i=0;i<0;i++)
    

}