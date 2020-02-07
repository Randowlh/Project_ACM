#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
vector<int> mp[10010];
struct node{
    int t;
    int now;
};
int n,m,k;
int ans=0;
int anst;
void bfs(int s){
    int book[10010];
    for(int i=0;i<=n;i++){
        book[i]=1;
    }
    node x;
    x.now=s;
    anst=0;
    ans=0;
    x.t=0;
    book[s]=0;
    queue<node> q;
    q.push(x);
    while(!q.empty()){
        for(int i=0;i<mp[q.front().now].size();i++){
            if(book[mp[q.front().now][i]]){
                book[mp[q.front().now][i]]=0;
                node x;
                x.now=mp[q.front().now][i];
                x.t=q.front().t+1;
                if(anst==x.t){
                    ans=min(x.now,ans);
                }
                if(anst<x.t){
                    anst=x.t;
                    ans=x.now;
                }
                q.push(x);
            }
        }
        q.pop();
    }
    return;
}
void work(){
    scanf("%d%d%d",&n,&m,&k);
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=0;i<k;i++){
        int s;
        scanf("%d",&s);
        bfs(s);
        printf("%d\n",ans);
    }
    return;
}
int main(){
  //  freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}