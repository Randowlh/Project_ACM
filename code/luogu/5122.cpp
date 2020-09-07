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
const int maxm= 210000;
const int maxn = 51000;
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
int n,m;
int dui[maxn];
int tdis[maxn];
int dis[maxn];
bool vis[maxn];
int cnt[maxn];
vector<int> tt;
queue<int> q;
bool spfa(int s){
    while(!q.empty()){
        int t=q.front();
        q.pop();
        vis[t]=0;
         for(int i=head[t];i;i=eg[i].nxt){
             int to=eg[i].to,w=eg[i].w;
             if(dis[to]>dis[t]+w){
                 dis[to]=dis[t]+w;
                 if(!vis[to]){
                     vis[to]=1;
                     q.push(to);
                 }
             }
         }
     }
     return true;
}
void work()
{
    int k;
    rd(n),rd(m),rd(k);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
        add(v,u,w);
    }
     for(int i=1;i<=n;i++)
         vis[i]=cnt[i]=0,dis[i]=llinf;
     cnt[n]=vis[n]=1;
     dis[n]=0;
     q.push(n);
    spfa(n);
    for(int i=1;i<=n;i++)
        tdis[i]=dis[i],dui[i]=0;
    int a,b;
    for(int i=1;i<=k;i++){
        rd(a),rd(b);
        dui[a]=max(b,dui[a]);
    }
    for(int i=1;i<=n;i++){
        if(dui[i]){
            q.push(i);
            vis[i]=1;
            dis[i]-=dui[i];
        }else{ 
        dis[i]=llinf;
        vis[i]=0;
        }
    }
    spfa(n);
    for(int i=1;i<n;i++){
        wt(tdis[i]>=dis[i]),putchar('\n');
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