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
const int maxm= 210000;
const int maxn = 210000;
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
int dis[maxn];
bool vis[maxn];
int cnt[maxn];
bool spfa(int s){
    for(int i=1;i<=n;i++)
        vis[i]=cnt[i]=0,dis[i]=llinf;
    cnt[s]=vis[s]=1;
    dis[s]=0;
    queue<int> q;
    q.push(s);
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
                    cnt[to]++;
                    if(cnt[to]>=n){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void work()
{
    rd(n),rd(m);
    int u,v,w;
    cl(n);
    for(int i=0;i<m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w);
        if(w>=0)
            add(v,u,w);
    }
    if(spfa(1))
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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