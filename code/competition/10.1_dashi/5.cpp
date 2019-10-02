#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
const int LOG=20;
struct Node{
    int to,next;
}q[maxn];
int head[maxn],cnt=0;
void add_edge(int from,int to){
    q[cnt].to=to;
    q[cnt].next=head[from];
    head[from]=cnt++;
}
struct LCA_ST{
    int anc[maxn][LOG],depth[maxn];
    void bfs(int root){
        queue<int>que;
        depth[root]=0;
        anc[root][0]=root;
        que.push(root);
        while(!que.empty()){
            int x=que.front();
            que.pop();
            for(int i=1;i<LOG;i++){
                anc[x][i]=anc[ anc[x][i-1] ][i-1];
            }
            for(int i=head[x];i!=-1;i=q[i].next){
                int to=q[i].to;
                if(to==anc[x][0]) continue;
                depth[to]=depth[x]+1;
                anc[to][0]=x;
                que.push(to);
            }
        }
    }
    void swim(int &x,int h){
        for(int i=0;h>0;i++){
            if(h&1)
                x=anc[x][i];
            h>>=1;
        }
    }
    int query(int x,int y){
        if(depth[x]<depth[y]) swap(x,y);
        swim(x,depth[x]-depth[y]);
        if(x==y) return x;
        for(int i=LOG-1;i>=0;i--){
            if(anc[x][i]!=anc[y][i]){
                x=anc[x][i];
                y=anc[y][i];
            }
        }
        return anc[x][0];
    }
}lca;
int main()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    int n,m,root;
    scanf("%d%d%d",&n,&m,&root);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }
    lca.bfs(root);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",lca.query(a,b));
    }
    return 0;
}