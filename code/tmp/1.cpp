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
const ll mod =  1000000007;
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 110000;
inline int exgcd(int a, int b, int& x, int& y) {
   x = 1, y = 0;
   int x1 = 0, y1 = 1, a1 = a, b1 = b;
   while (b1) {
     int q = a1 / b1;
     tie(x, x1) = make_tuple(x1, x - q * x1);
     tie(y, y1) = make_tuple(y1, y - q * y1);
     tie(a1, b1) = make_tuple(b1, a1 - q * b1);
   }
   return a1;
}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int a,int b){ int tmp,ans;exgcd(a,b,ans,tmp);return (ans%b+b)%b;}
int a[maxn],b[maxn],xs[maxn],flag[maxn];
void work()
{
   int n,x;
   while(scanf("%lld%lld",&n,&x)!=EOF){
      int cnt=0;
      int bg=1;
      for(int i=1;i<=n;i++){
         rd(a[i]);
         flag[i]=0;
      }
      for(int i=1;i<=n;i++)
         rd(b[i]);
      int ans=0;
      for(int i=1;i<=n;i++){
         ans+=a[i]*b[i];
         ans%=mod;
      }
      ans=ans*powmod(x,n-1)%mod;
      ans+=powmod(x,n);
      ans%=mod;
      cout<<ans<<endl;
      continue;
      /*
      while(bg<=n&&(!a[bg]||!b[bg]))
         bg++;
      if(bg>n){
         cout<<powmod(x,n)<<endl;
         continue;
      }
      int ans=1;
      for(int i=1;i<=n;i++){
         if(a[i])
         ans=(ans*a[i])%mod;
         else cnt++,flag[i]=1;
      }
      for(int i=1;i<=n;i++){
         if(b[i])
         ans=(ans*b[i])%mod;
         else if(!flag[i])
            cnt++,flag[i]=1;
      }
      for(int i=bg;i<=n;i++)
         xs[i]=niyuan(a[i]*b[i]%mod,mod);
      int ys=(1+(x)*xs[bg])%mod;
      for(int i=bg+1;i<=n;i++){
         if(!flag[i])
            ys=(ys+(a[i]*b[i]%mod*xs[bg]%mod))%mod;
      }
      int rs=1;
      // for(int i=bg+1;i<=n;i++)
      //    if(!flag[i])
      //       rs=(rs*x%mod*xs[i]%mod)%mod;
      cout<<ans*ys%mod*rs%mod*powmod(x,cnt+bg-1)%mod<<endl;
   */
   }
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