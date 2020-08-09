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
const int maxm= 10000;
struct Edges{
    int to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
void add(int u,int v){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    //edge[ecnt].w=w;
    head[u]=ecnt;
}
int n;
int dp[2][10100];
int vl[10100];
int du[10100];
int sz[10100];
int root;
void dfs(int now){
    if(!sz[now]){
        dp[0][now]=0;
        dp[1][now]=vl[now];
        return;
    }
    for(int i=head[now];i;i=edge[i].next){
        dfs(edge[i].to);
        dp[0][now]+=max(dp[0][edge[i].to],dp[1][edge[i].to]);
        dp[1][now]+=dp[0][edge[i].to];
    }
    dp[1][now]+=vl[now];
}
void work()
{
    rd(n);
    for(int i=1;i<=n;i++)
        rd(vl[i]);
    int u,v;
    for(int i=1;i<=n-1;i++)
        rd(v),rd(u),add(u,v),du[v]++,sz[u]++;
    for(int i=1;i<=n;i++)
        if(!du[i]){
            root=i;
            break;
        }
    dfs(root);
    cout<<max(dp[0][root],dp[1][root])<<endl;
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