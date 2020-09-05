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
struct edge{
    int nxt,to,w;
}eg[510000];
int head[110000];
int ecnt=0;
inline void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].to=v;
    eg[ecnt].w=w;
    head[u]=ecnt;
}
int n,m,t;
int cr[110000];
int dis[110000];
bool flag[110000];
int pre[110000];
void spfa(int s){
    for(int i=1;i<=n;i++)
        dis[i]=llinf;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    flag[s]=1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        flag[t]=0;
        for(int i=head[t];i;i=eg[i].nxt){
            if(dis[eg[i].to]>=dis[t]+eg[i].w){
                if(dis[eg[i].to]==dis[t]+eg[i].w){
                    MIN(pre[eg[i].to],t);
                    continue;
                }
                dis[eg[i].to]=dis[t]+eg[i].w;
                pre[eg[i].to]=t;
                if(!flag[eg[i].to]){
                    q.push(eg[i].to);
                    flag[eg[i].to]=true;
                }
            }
        }
    }
}
void work()
{
    rd(n),rd(m),rd(t);
    for(int i=1;i<=n;i++)   
        rd(cr[i]);
    int u,v,w;
    for(int i=0;i<m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
        add(v,u,w);
    }
    spfa(1);
    set<pair<int,int>> s;
    for(int i=1;i<=n;i++)
        s.insert(make_pair(dis[i],i));
    while(!s.empty()){
        int t=s.rbegin()->second;
        cr[pre[t]]+=cr[t];
        s.erase(s.find(*s.rbegin()));
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        MAX(ans,(dis[i]-t)*cr[i]);
    }
    cout<<ans<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}