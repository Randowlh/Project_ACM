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
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 110000;
struct Edges{
    int w,to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
set<pair<int,int>> ss;
int ans=0;
int n,s;
void dfs(int x,int sum,int fa){
    int cnt=0;
    while(sum>s){
        // cnt++;
        //  if(cnt>10)
        //  exit(0);
        pair<int,int> tt=*ss.rbegin();
        // cout<<sum<<endl;
        //  cout<<tt.first<<' '<<tt.second<<endl;
        // for(auto i=ss.begin();i!=ss.end();i++)
        //    cout<<">>"<<i->first<<' '<<i->second<<endl;
        ss.erase(tt);
        sum-=tt.first-(tt.first/2);
        cout<<"jian"<<tt.first-(tt.first/2)<<endl;
        tt.first>>=1;
        edge[tt.second].w>>=1;
        ss.insert(tt);
        ans++;
         cout<<"now="<<x<<endl;
    }
    for(int i=head[x];i;i=edge[i].next){
        if(edge[i].to==fa)
        continue;
        ss.insert(make_pair(edge[i].w,i));
        dfs(edge[i].to,sum+edge[i].w,x);
        ss.erase(make_pair(edge[i].w,i));
    }
    return;
}
void work()
{
    cin>>n>>s; 
    ss.clear();
    for(int i=0;i<=n;i++)
    head[i]=0;
    ecnt=0;
    ans=0;
    int u,v,w;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs(1,0,-1);
    cout<<ans<<endl;
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}