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
const int maxm= 1;
const int maxn = 510000;
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
    cout<<u<<' '<<v<<' '<<w<<"dsadasdas"<<endl;
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
map<pair<int,int>,int> M;
vector<pair<int,pair<int,int>>> arr;
void work()
{
    ecnt=0;
    int n,m;
    rd(n),rd(m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        cout<<"u="<<u<<" v="<<v<<" w="<<w<<endl;
        if(v>u)
            swap(v, u);
        add(u,v,w);
        arr.push_back(make_pair(w,make_pair(u,v)));
        add(v,u,w);
        cout<<"u="<<u<<" v="<<v<<" w="<<w<<endl;
    }
    for(int i=1;i<=ecnt;i++){
        cout<<eg[i].to<<' '<<eg[i].nxt<<' '<<i<<endl;
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    int aa=0;
    cout<<">>>"<<endl;
    for(int i=0;i<arr.size();i++){
        int u=arr[i].second.first;
        int v=arr[i].second.second;
        int w=arr[i].first;
        int ans=0;
        cout<<u<<' '<<v<<endl;
        for(int j=head[u];j;j=eg[j].nxt){
            if(eg[j].w<=w){
                continue;
            }
            int to=eg[j].to,fr=u;
            if(to>fr)
                swap(to, fr);
            MAX(ans,M[make_pair(fr,to)]);
        }
        cout<<"dadads"<<endl;
        for(int j=head[v];j;j=eg[j].nxt){
            if(eg[j].w<=w)
                continue;
            int to=eg[j].to,fr=v;
            if(to>fr)
                swap(to, fr);
            MAX(ans,M[make_pair(fr,to)]);
        }
        cout<<ans<<endl;
        M[make_pair(u,v)]=ans+1;
        MAX(aa,ans+1);
    }
    cout<<aa<<endl;
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