#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 11000;
int date[110][110];
struct Edges{
    int w,to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
inline void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
inline int find(int x,int t){
    if(date[t][x]==x)
        return x;
    else return date[t][x]=find(date[t][x],t);
}
inline void merge(int t,int a,int b){
    int l=find(a,t);
    int r=find(b,t);
    date[t][l]=r;
}
int n,m;
int ans=0;
int xia=0;
void dfs(int x,int sum){
    if(sum==0)
    return;
    if(x==n){
        ans+=sum;
        ans%=mod;
        cout<<ans<<endl;
        return;
    }
    int t=find(x,x);
    for(int i=head[x];i;i=edge[i].next){
        int a=find(edge[i].to,x);
        if(a==t)
        continue;
        for(int i=1;i<=n;i++)
        date[x+1][i]=date[x][i];
        merge(x+1,a,t);
        dfs(x+1,sum&edge[i].w);
    }
}
void work()
{
    register int i;
    ans=0,xia=0;
    rd(n), rd(m);
    register int u,v,w;
    ecnt=0;
    for(i=0;i<=n;i++)
    head[i]=0,date[1][i]=i;
    for(i=0;i<m;i++){
        rd(u), rd(v), rd(w);
        add(v,u,w);
        add(u,v,w);
    }
    dfs(1,(1LL<<30)-1);
    printf("%lld\n",ans*powmod(xia,mod-2)%mod);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1;
    //cin>>t;
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}