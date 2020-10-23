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
template<class T>
void wt(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) wt(x / 10);
    putchar('0' + x % 10);
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this

#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int sz[110000];
vector<int> mp[110000];
int ps[110000];
int hp[110000];
int flag=0;
void dfs1(int now,int fa){
    sz[now]=ps[now];
    for(int i=0;i<mp[now].size();i++){
        if(mp[now][i]==fa)
            continue;
        dfs1(mp[now][i],now);
        sz[now]+=sz[mp[now][i]];
    }
}
void dfs(int now,int fa){
    for(int i=0;i<mp[now].size();i++){
        if(mp[now][i]==fa)
            continue;
        if(flag)
            return;
        dfs(mp[now][i],now);    
    }
    int h=0,u=0;
    for(int i=0;i<mp[now].size();i++){
        if(mp[now][i]==fa)
            continue;
        h+=hp[mp[now][i]];
    }
    if(h>hp[now]+ps[now]){
        flag=1;
    }
    return ;
}
void work()
{
    flag=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].clear();
    }
    for(int i=1;i<=n;i++)
        cin>>ps[i];
    for(int i=1;i<=n;i++)
        cin>>hp[i];
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs1(1,-1);
    for(int i=1;i<=n;i++){
        if((sz[i]-hp[i])<0||(sz[i]-hp[i])%2){
            cout<<"NO"<<endl;
            return ;
        }
    }
    dfs(1,-1);
    if(flag)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}