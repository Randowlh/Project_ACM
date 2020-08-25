#include <bits/stdc++.h>
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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (1 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1100000;
struct Edges{
    int to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
multiset<int> eg;
int yz[1100000];
int sz[1100000];
void add(int u,int v){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    //edge[ecnt].w=w;
    head[u]=ecnt;
}
int n;
void dfs(int now,int fa){
    for(int i=head[now];i;i=edge[i].next){
        if(edge[i].to==fa)
            continue;
        eg.insert(sz[edge[i].to]*(n-sz[edge[i].to]));
        dfs(edge[i].to,now);
    }
}
void tj(int now,int fa){
    sz[now]=1;
    for(int i=head[now];i;i=edge[i].next){
        if(edge[i].to==fa)
            continue;
        tj(edge[i].to,now);
        sz[now]+=sz[edge[i].to];
    }
}
void work()
{
    rd(n);
    eg.clear();
    ecnt=0;
    for(int i=0;i<=n;i++)
        head[i]=0;
    int u,v;
    for(int i=0;i<n-1;i++){
        rd(u),rd(v);
        add(u,v);
        add(v,u);
    }
    int m;
    rd(m);
    for(int i=1;i<=m;i++)
        rd(yz[i]);
    sort(yz+1,yz+m+1);
    tj(1,-1);
    dfs(1,-1);
    int ans=0;
    while(m<eg.size()){
        ans+=*eg.begin();
        ans%=mod;
        eg.erase(eg.begin());
    }
    int tt=eg.size();
    for(int i=1;i<=tt-1;i++){
        ans+=(*eg.begin())*yz[i]%mod;
        ans%=mod;
        eg.erase(eg.begin());
    }
    int now=1;
    for(int i=tt;i<=m;i++)
        now=(now*yz[i])%mod;
    ans+=(*eg.begin())*now%mod;
    ans%=mod;
    printf("%lld\n",ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}