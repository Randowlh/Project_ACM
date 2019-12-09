#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int  date[10010];
int map[10010];
int find(int x){
    if(date[x]==x){
        return x;
    }else{
        date[x]=find(date[x]);
        return date[x];
    }
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l==r){
        return ;       
    }else{
        date[l]=r;
        return ;
    }
}
int main(){
    int n;
    int m;
    while(cin>>n){
        if(n==0){
            break;
        }
        cin>>m;
        int s;
        int e;
        for(int i=0;i<=n;i++){
            date[i]=i;
            map[i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&s,&e);
            merge(s,e);
        } 
        int  ans=0;
        for(int i=1;i<=n;i++){
            if(map[find(i)]==0){
                map[find(i)]=1;
                ans++;
            }
        }
        cout<<ans-1<<endl;
    }    
}