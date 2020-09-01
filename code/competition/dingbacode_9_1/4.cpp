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
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 510000;
const int maxn = 110000;
struct Edges{
    int to,next;
}edge[1010000];
int head[110000];
int ecnt=0;
void add(int u,int v){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    head[u]=ecnt;
}
int n,m,k,s,ed;
int cl[110000];
int ans[110000];
struct node{
   int x,cnt,tm;
   node(int a,int b,int c):x(a),cnt(b),tm(c){}
   bool operator<(node a) const {
      return tm>a.tm;
   }
};
void work()
{
   int u,v;
   rd(n), rd(m), rd(k), rd(s), rd(ed);
   for(int i=1;i<=n;i++)
      rd(cl[i]),ans[i]=llinf;
   for(int i=1;i<=m;i++){
      rd(u),rd(v);
      add(u,v);
     // add(v,u);
   }
   queue<node> q;
   q.push(node(s,1,1));
   //vis[s]=1;
   ans[s]=1;
   while(!q.empty()){
      node t=q.front();
      q.pop();
    //  cout<<"time="<<t.tm<<' '<<t.x<<' '<<t.cnt<<endl;
      for(int i=head[t.x];i;i=edge[i].next){
         int to=edge[i].to;
         if(cl[to]==cl[t.x]){
            int f=0;
            if(t.cnt==k)
               f=1;
            if(ans[to]>t.tm+f){
            ans[to]=t.tm+f;
            q.push(node(to,t.cnt%k+1,ans[to]));
            }
         }else{
            if(ans[to]>t.tm+1){
            ans[to]=t.tm+1;
            q.push(node(to,1,ans[to]));
            }
         }
      }
   }
   if(ans[ed]!=llinf)
   cout<<ans[ed]<<endl;
   else cout<<-1<<endl;
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