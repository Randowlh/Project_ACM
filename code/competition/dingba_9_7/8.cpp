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
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 510000;
const int maxn = 510000;
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
pair<int,pair<int,int>>edge[510000];
map<pair<int,int>,int> M;
int vis[110000];
int dfs(int pos,int w){
    int ans=0;
    //cout<<"w="<<w<<" pos="<<pos<<endl;
    if(M[make_pair(pos,w)])
        return M[make_pair(pos,w)];
    for(int i=head[pos];i;i=eg[i].nxt){
        if(eg[i].w<w){
            ans=max(ans,dfs(eg[i].to,eg[i].w));
        }
    }
    M[make_pair(pos,w)]=ans+1;
    return ans+1;
}
void work()
{
    int n,m;
    rd(n), rd(m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u), rd(v),rd(w);
        add(u,v,w);
        add(v,u,w);
        edge[i]=make_pair(w,make_pair(u,v));
    }
    sort(edge+1,edge+m+1);
    reverse(edge+1,edge+m+1);
    int ans=0;
    for(int i=1;i<=m ;i++){
        int u=edge[i].second.first;
        int v=edge[i].second.second;
        int w=edge[i].first;
        //cout<<u<<' '<<v<<' '<<w<<endl;
        if(!vis[u])ans=max(ans,dfs(u,w));
        if(!vis[v])ans=max(ans,dfs(v,w));
        vis[u]=1;vis[v]=1;
    }
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}