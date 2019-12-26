#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int b[600000];
int n;
//int a[100000];
int lowbit(int x){
    return x&-x;
}
void add(int x,int k){
    for(;x<=n;x+=x&-x)b[x]+=k; return;
}
int ask(int x){
    int ans=0;
    for(;x>=1;x-=x&-x)ans+=b[x];
    return ans;
}
int asks(int x,int y){
    return ask(y)-ask(x-1);
}
int main(){
    int m;
    cin>>n>>m;
    int v;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        add(i,v);
    }
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&v,&x,&y);
        if(v==1){
            add(x,y);
        }else{
            cout<<asks(x,y)<<endl;
        }
    }
    return 0;
}