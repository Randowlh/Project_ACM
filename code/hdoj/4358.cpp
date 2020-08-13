#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x, T y) {
    if (y>x)x=y;
}
template<class T>inline void MIN(T &x, T y) {
    if (y<x)x=y;
}
template<class T>inline void rd(T &x) {
    x=0;char o, f=1;
    while (o=getchar(), o<48)if (o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while (o=getchar(), o>47);
    x*=f;
}
inline void wt(__int128 X)
{
    if(X<0) {X=~(X-1); putchar('-');}
    if(X>9) wt(X/10);
    putchar(X%10+'0');
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 110000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a, ll b) {
    ll res=1;a%=mod; assert(b>=0); for (;b;b>>=1) {
        if (b&1)res=res*a%mod;a=a*a%mod;
    }
    return res;
}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 110000;
struct Edges {
    int  to, next;
}edge[maxm];
int head[maxm];
int ecnt=0;
int vl[110000];
int hson[110000];
int ft[110000];
int cnt[110000];
int ans[110000];
int lsh[110000];
int isq[110000];
int vlq[110000];
int qq[110000];
int len,ct;
int n,k;
map<int,int> M;
void add(int u, int v) {
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    //edge[ecnt].w=w;
    head[u]=ecnt;
}
pair<int,int> dfs(int now,int fa){
    ft[now]=fa;
    int ma=0,mix=-1;
    int ans=1;
    if(isq[now]==ct)
        vlq[now]=1;
    hson[now]=-1;
    for(int i=head[now];i;i=edge[i].next){
        if(edge[i].to!=fa){
            pair<int,int> t=dfs(edge[i].to,now);
            if(t.second)
                vlq[now]=1;
            ans+=t.first;
            if(t.first>ma)
                ma=t.first,mix=edge[i].to;
        }
    }
    hson[now]=mix;
    return make_pair(ans,vlq[now]);
}   
void calc(int now,int flag){
    cnt[vl[now]]+=flag;
    for(int i=head[now];i;i=edge[i].next){
        if(edge[i].to!=ft[now])
            calc(edge[i].to,flag);
    }
}
void solve(int now,int opt){
    for(int i=head[now];i;i=edge[i].next)
        if(edge[i].to!=ft[now]&&edge[i].to!=hson[now])
            solve(edge[i].to,1);
    if(hson[now]!=-1)
        solve(hson[now],0);
    for(int i=head[now];i;i=edge[i].next)
        if(edge[i].to!=hson[now]&&edge[i].to!=ft[now])
            calc(edge[i].to,1);
    cnt[vl[now]]++;
    ans[now]=0;
    for(int i=1;i<=len;i++)
        if(cnt[i]==k)
            ans[now]++;
    if(opt){
        cnt[vl[now]]--;
        for(int i=head[now];i;i=edge[i].next){
            if(edge[i].to!=ft[now])
            calc(edge[i].to,-1);
        }
    }
}
void work()
{
    M.clear();
    rd(n), rd(k);
    int u,v;
    for(int i=0;i<=n;i++)
        cnt[i]=head[i]=0;
    ecnt=0;
    for(int i=1;i<=n;i++)
        rd(vl[i]),lsh[i]=vl[i];
    sort(lsh+1,lsh+n+1);
    len=unique(lsh+1,lsh+n+1)-lsh-1;
    for(int i=1;i<=len;i++)
        M[lsh[i]]=i;
    for(int i=1;i<=n;i++)
        vl[i]=M[vl[i]];
    for(int i=1;i<=n-1;i++){
        rd(u),rd(v);
        add(u,v);
        add(v,u);
    }
    dfs(1,-1);
    int q;
    rd(q);
    for(int i=1;i<=q;i++){
        rd(qq[i]);
        isq[qq[i]]=ct;
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    #endif
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    //cin>>t;
    rd(t);
    while (++ct<=t)
    {  
        printf("Case #%d:\n",ct);
        work();
    }
    return 0;
}