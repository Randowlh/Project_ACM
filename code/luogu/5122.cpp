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
const int maxm= 1;
const int maxn = 510000;
int ecnt=0;
struct edge{
    int w,to,nxt;
}eg[110000];
int head[50005];
inline void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].to;
    eg[ecnt].w=w;
    head[u]=ecnt;
}
int flag[50005];
int dis[50005];
vector<int> v;
int n,m,k;
void dij(int a){
    for(int i=1;i<=n;i++)  
        dis[i]=llinf;
    dis[a]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push(pair<int,int>(0,a));
    while(!q.empty()){
        pair<int,int> t=q.top();
        q.pop();
        if(dis[t.second]<t.first)
            continue;
        for(int i=head[t.first];i; i = eg[i].nxt){
            int& to=eg[i].to;
            if(eg[i].w+dis[t.second]<dis[to]){
                dis[to]=eg[i].w+dis[t.second];
                q.push(make_pair(dis[to],to));
            }
        }
    }
}
void work()
{
    rd(n),rd(m),rd(k);
    memset(dis,-1,sizeof(dis));
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
        add(v,u,w);
    }
    int pos,v;
    for(int i=1;i<=n;i++){
        rd(pos),rd(v);
    }
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