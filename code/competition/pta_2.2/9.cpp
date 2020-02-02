#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{   
    int a,b;
    /* data */
}mp[5010];
int flag[5010];
int fl[1000];
int date[1000];
int n,m;
int find(int x){
    if(date[x]==x){
        return x;
    }else {
        date[x]=find(date[x]);
        return date[x];
    }
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l==r)
    return;
    date[l]=r;
    return;
}
int tj(){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(find(i));
    }
    for(int i=0;i<n;i++){
        if(fl[i]==0)
        s.erase(i);
    }
    return s.size();
}
void init(){
    for(int i=0;i<n;i++){
        date[i]=i;
    }
    for(int i=0;i<m;i++){
        if(flag[i]){
            merge(mp[i].a,mp[i].b);
        }
    }
    return;
}
void work(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        date[i]=i;
    }
    memset(flag,1,sizeof(flag));
    memset(fl,1,sizeof(fl));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[i].a=a;
        mp[i].b=b;
        merge(a,b);
    }
    int now=tj();
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int des;
        cin>>des;
        fl[des]=0;
        for(int i=0;i<m;i++){
            if(flag[i]&&(mp[i].a==des||mp[i].b==des)){
                flag[i]=0;
            }
        }
        init();
        int t=tj();
        if(t>now){
            
            cout<<"Red Alert: City "<<des<<" is lost!"<<endl;
        }else{
            cout<<"City "<<des<<" is lost."<<endl;
        }
        now=t;
    }
    if(k==n)
    cout<<"Game Over."<<endl;
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
/*
City 1 is lost.
City 2 is lost.
Red Alert: City 0 is lost!
City 4 is lost.
City 3 is lost.
Game Over.


*/