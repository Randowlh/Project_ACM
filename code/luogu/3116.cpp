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
vector<int> mp[110],topo;
int  du[110],dp[110][11000];
struct edge{
   int w1,w2,to,nxt;
}eg[maxn];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w1,int w2){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w1=w1;
   eg[ecnt].w2=w2;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
void work()
{
    ecnt=0;
    int n,m;
    cin>>n>>m;   
    int u,v,w1,w2;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w1>>w2;
        add(v,u,w1,w2);
        mp[u].push_back(v);
    }
    set<int> s1,s2;
    int ans=llinf;
    dp[1][0]=3;
    for(int i=1;i<=n;i++){
        for(int j=1;j<10005;j++){
            dp[i][j]=0;
            for(int k=head[i];k;k=eg[k].nxt){
                int to=eg[k].to,w1=eg[k].w1,w2=eg[k].w2;
                if(w1<=j&&(dp[to][j-w1]&1)){    
                    dp[i][j]|=1;
                }
                if(w2<=j&&(dp[to][j-w2]&2)){
                    dp[i][j]|=2;
                }
            }
        }
    }
    for(int i=0;i<=10005;i++){
        if(dp[n][i]==3){
            cout<<i<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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