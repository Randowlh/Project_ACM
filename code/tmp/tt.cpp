#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define MP make_pair
#define pb push_back
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
const ll llinf = 4223372036854775807;
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 1010000;
struct seg{
   int lazy[maxn<<2];
   void build(int pos,int l,int r){
      if(l==r){
         lazy[pos]=1;
         return;
      }
      int mid=(l+r)/2;
      build(lson(pos),l,mid);
      build(rson(pos),mid+1,r);
   }
   void update(int pos,int l,int r,int ql,int qr,int v){
      if(ql<=l&&qr>=r){
         lazy[pos]+=v;
         lazy[pos]%=mod;
         return;
      }
      int mid=(l+r)>>1;
      if(ql<=mid)
         update(lson(pos),l,mid,ql,qr,v);
      if(qr>=mid+1)
         update(rson(pos),mid+1,r,ql,qr,v);
   }
   int get(int pos,int l,int r,int q){
      if(l==r)
         return lazy[pos];
      int now=lazy[pos];
      int mid=(l+r)>>1;
      if(q<=mid)
         now+=get(lson(pos),l,mid,q);
      else now+=get(rson(pos),mid+1,r,q);
      return now%mod;
   }
}T;
struct node{
   int l,r;
   int v;
   int opt;
}cz[maxn];
int pre[maxn];
void work()
{
   int n,m;
   rd(n),rd(m);
   int opt;
   int l,r;
   T.build(1,1,m);
   for(int i=1;i<=m;i++){
      rd(opt);
      cz[i].opt=opt;
      rd(cz[i].l),rd(cz[i].r);
      if(opt==1)
         rd(cz[i].v);
      else cz[i].v=1;
   }
   for(int i=m;i>=1;i--){
      int bei=T.get(1,1,m,i);
      if(cz[i].opt==1){
         pre[cz[i].l]+=bei*cz[i].v%mod;
         pre[cz[i].r+1]-=bei*cz[i].v%mod;
         pre[cz[i].l]%=mod;
         pre[cz[i].r+1]%=mod;
         pre[cz[i].r+1]+=mod;
         pre[cz[i].r+1]%=mod;
      }else{
         T.update(1,1,m,cz[i].l,cz[i].r,bei);
      }
   }
   int now=0;
   for(int i=1;i<=n;i++){
      now+=pre[i];
      now=(now%mod+mod)%mod;
      wt(now),pt(' ');
   }
   pt('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}