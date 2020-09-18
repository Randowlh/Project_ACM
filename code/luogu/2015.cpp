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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1000;
int n,q;
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
int dp[110][110];
int sz[110];
int sg[110];
int dfs(int pos,int fa,int now){
    if(dp[pos][now]!=-1)
        return dp[pos][now];
    if(now==0)
        return 0;
    vector<int> v;
    int ans=0;
    for(int i=head[pos];i;i=eg[i].nxt){
        if(eg[i].to!=fa)
            v.push_back(eg[i].to);
    }
    if(v.size()==0){
        ans=0;
    }else
    if(v.size()==1)
        ans=dfs(v[0],pos,now-1);
    else
    for(int i=max(0LL,now-1-sz[v[1]]);i<=min(sz[v[0]],now-1)&&now-i-1>=0;i++){
            int tans=0;
            tans=dfs(v[0],pos,i);
            tans+=dfs(v[1],pos,now-i-1);   
            MAX(ans,tans);
    }
    ans+=sg[pos];
    dp[pos][now]=ans;
    return ans;
}
void pre(int pos,int fa){
    sz[pos]=1;
    for(int i=head[pos];i;i=eg[i].nxt){
        if(eg[i].to==fa)
            continue;
        sg[eg[i].to]=eg[i].w;
        pre(eg[i].to,pos);
        sz[pos]+=sz[eg[i].to];
    }
}
void work()
{
    cin>>n>>q;
    int u,v,w;
    memset(dp,-1, sizeof(dp));
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    pre(1,-1);
    cout<<dfs(1,-1,q+1)<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}