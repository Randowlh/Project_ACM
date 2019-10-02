#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <queue>
#include <map>
#define ll long long 
#define ri register int 
#define ull unsigned long long
using namespace std;
const int maxn=500005;
const int inf=0x7fffffff;
template <class T>inline void read(T &x){
    x=0;int ne=0;char c;
    while(!isdigit(c=getchar()))ne=c=='-';
    x=c-48;
    while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+c-48;
    x=ne?-x:x;
    return ;
}
int n,m,s,t;
struct Edge{
    int ne,to;
}edge[maxn<<1];
struct QU{
    int d,id;
    QU(int x,int y){d=x,id=y;}
    QU(){;}
};
vector <QU>q[maxn];
int h[maxn],num_edge=0,ans[maxn];
inline void add_edge(int f,int to){
    edge[++num_edge].ne=h[f];
    edge[num_edge].to=to;
    h[f]=num_edge;
    return;
}
int fa[maxn],vis[maxn];
int get(int x){
    if(fa[x]!=x)fa[x]=get(fa[x]);
    return fa[x];
}
void dfs(int cur){
    int u,v;
    vis[cur]=1;
    for(ri i=h[cur];i;i=edge[i].ne){
        v=edge[i].to;
        if(vis[v])continue;
        dfs(v);
        fa[v]=cur;
    }
    for(ri i=0;i<q[cur].size();i++){
        u=q[cur][i].d,v=q[cur][i].id;
        if(vis[u]==2){
            ans[v]=get(u);
        }
    }
    vis[cur]=2;
    return ;
}
int main(){
    int x,y;
    read(n),read(m),read(s);
    for(ri i=1;i<n;i++){
        read(x),read(y);
        add_edge(x,y);
        add_edge(y,x);
        fa[i]=i;
    }fa[n]=n;
    for(ri i=1;i<=m;i++){
        read(x),read(y);
        q[x].push_back(QU(y,i));
        q[y].push_back(QU(x,i));
    }
    dfs(s);
    for(ri i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}