#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int date[1010];
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
    if(l==r)return;
    date[l]=r;
    return ;
}
int main(){
    int t,n,m;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            date[i]=i;
        }
        int tmp1,tmp2;
        for(int i=0;i<m;i++){
            cin>>tmp1>>tmp2;
            merge(tmp1,tmp2);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(date[i]==i){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}