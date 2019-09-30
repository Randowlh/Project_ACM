#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=205;
vector<int>g[maxn];
int n,e[maxn][2],dis[maxn],tar;
int dfs(int u,int fa,int x)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa||v==x)continue;
        dis[v]=dis[u]+1;
        if(dis[v]>dis[tar])tar=v;
        dfs(v,u,x);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v),g[v].push_back(u);
        e[i][0]=u,e[i][1]=v;
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int u=e[i][0],v=e[i][1],w;
        tar=u;dis[u]=0;
        dfs(u,u,v);
        w=tar;dis[w]=0;
        dfs(w,w,v);
        int d1=dis[tar];
        tar=v;dis[v]=0;
        dfs(v,v,u);
        w=tar;dis[w]=0;
        dfs(w,w,u);
        int d2=dis[tar];
        ans=max(ans,d1+d2);
    }
    printf("%d\n",ans);
    return 0;
}
