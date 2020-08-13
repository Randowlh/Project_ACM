#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const int MAXN=31010;
const int MAXE=31010;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
#define int long long
struct Node
{
    int to, next;
    bool cut;
};
template<class T>inline void rd(T &x) {
    x=0;char o, f=1;
    while (o=getchar(), o<48)if (o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while (o=getchar(), o>47);
    x*=f;
}
Node edge[310000];
int head[310000];
int ecnt;
int dfn[310000];
int low[310000];
int cnt=0;
int belong[310000];
int cnt2=0;
inline void addEdge(int u, int v)
{
    edge[ecnt].to=v;
    edge[ecnt].next=head[u];
    edge[ecnt].cut=false;
    head[u]=ecnt++;
}
void tarjan(int u, int e)
{
    low[u]=dfn[u]=++cnt;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (i==(e^1)) continue;
        if (dfn[v]==0)
        {
            tarjan(v, i);
            MIN(low[u], low[v]);
            if (low[v]>dfn[u])
            {
                edge[i].cut=1;
                edge[i^1].cut=1;
            }
        }
        else MIN(low[u], dfn[v]);
    }
}
void dfs(int u)
{
    dfn[u]=1;
    belong[u]=cnt2;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        if (edge[i].cut) continue;
        if (dfn[edge[i].to]==0) dfs(edge[i].to);
    }
}
void work()
{
    int n,m,q,a,b;
    rd(n), rd(m), rd(q);
    for (int i=0;i<=n;i++)
        head[i]=-1;
    cnt=0;
    for (int i=0;i<m;i++)
    {
            rd(a), rd(b);
            addEdge(a, b);
            addEdge(b, a);
    }
    for (int i=0;i<=n;i++)
        dfn[i]=belong[i]=0;
    cnt=cnt2=0;
    for (int i=1;i<=n;i++)
        if (dfn[i]==0)
            tarjan(i, -1);
    for (int i=0;i<=n;i++)
        dfn[i]=0;
    for (int i=1;i<=n;i++)
        if (dfn[i]==0){
            cnt2++;
            dfs(i);
        }
    int l,r;
    int lastans=0;
    for (int i=0;i<q;i++) {
        rd(a), rd(b);
        a^=lastans;
        b^=lastans;
        a%=m;
        if (belong[a]==belong[b]){
            printf("No\n");       
            lastans=0;
        }   
        else{ 
            printf("Yes\n");
            lastans=1;
        }
    }
}
signed main()
{

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    #endif
    int n, m, a, b, q;
    int _=0;
    rd(_);
    for (int t=0;t<_;t++) { 
        work();
    }
}