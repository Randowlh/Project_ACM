#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int bcj[200010];
int n,m;
int find(int x){
    if(bcj[x]==x){
        return x;
    }else{
        bcj[x]=find(bcj[x]);
        return bcj[x];
    }
}
void unin(int a,int b){
    bcj[a]=find(a);
    bcj[b]=find(b);
    bcj[bcj[a]]=bcj[b];
    return ;
}
int dates[200010];
int datee[200010];
int main(){
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        bcj[i]=i;
    }
    int ans=0;
    int s,e;
    for(int i=0;i<m;i++){
        cin>>dates[i]>>datee[i];
        unin(s,e);
    }
    int ans=0;
    for(int i=0;i<)

}