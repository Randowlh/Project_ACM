#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<string>
#define ll long long
#define inf 214748364
#define DB double
using namespace std;
inline int read()
{
int x=0,w=1;char ch=0;
while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
return x*w;

}
int tot,n,h[10000],H[10000],totA;
struct po{
int u,v,c,last;
}a[10000],A[10000];
int ans;
int num[100000],T,dfn[10000],low[10000];
int q[10000],l,in[10000],to[100000];
int R[10000];
void add(int u,int v)
{
tot++;
a[tot].v=v;
a[tot].last=h[u];
h[u]=tot;
}
void Add(int u,int v)
{
totA++;
A[totA].v=v;
A[totA].last=H[u];
H[u]=totA;
}
void tarjian(int u)
{
dfn[u]=low[u]=++T;
in[u]=1;l++,q[l]=u;
for(int i=h[u];i;i=a[i].last)
{
int v=a[i].v;
if(!dfn[v])
{
tarjian(v);
low[u]=min(low[u],low[v]);

} else if(in[v]) low[u]=min(dfn[v],low[u]);
}
if(dfn[u]==low[u])
{
num[0]++;
do{
in[q[l]]=0;
to[q[l]]=num[0];
num[num[0]]+=2;
}while(q[l--]!=u);

}
}
int main()
{
n=read();
for(int i=1;i<=n;i++)
{
int x;
while(scanf("%d",&x)!=EOF)
{
if(x==1) break;
add(i,x);
//add(x,i);

}

}
for(int i=1;i<=n;i++)
if(!dfn[i]) tarjian(i);
for(int i=1;i<=tot;i++)
{
int u=a[i].u;int v=a[i].v;
if(to[u]==to[v]) continue;
Add(to[u],to[v]);
R[to[v]]++;

}
for(int i=1;i<=num[0];i++)
{
if(R[i]==0) ans++;

}
printf("%d",ans);
return 0;
}
