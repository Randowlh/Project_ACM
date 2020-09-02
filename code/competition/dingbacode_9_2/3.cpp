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
const int maxm= 1;
const int maxn = 510000;
inline ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int x) { return powmod(x, mod - 2); }
int y[500005],x[500005];
int k,n;
int a[1100];
int calc(int x){
   int ans=0;
   for(int i=1;i<=k;i++){
      ans+=(a[i]*powmod(x,a[i]))%mod;
      ans%=mod;
   }
   return ans;
}
void work()
{
   rd(k),rd(n);
   int ma=1;
   for(int i=1;i<=k;i++){
      rd(a[i]);
      MAX(ma,a[i]);
   }
   //int vl=n;
   //n=ma;
   int ans=0;
   for(int i=1;i<=n;i++){
      ans+=calc(i);
      ans%=mod;
   }
   cout<<ans<<endl;
   return ;
   // for(int i=1;i<=n;i++){
   //    int t=y[i];
   //    for(int j=1;j<=n;j++){
   //       if(i==j)
   //          continue;
   //       t=(t*niyuan(i-j))%mod;
   //    }
   //    for(int j=0;j<=n;j++)
   //       x[j]=t;
   //    int now=1;
   //    for(int j=n-1;j>=0;j--){
   //       x[j]=(x[j]*now)%mod;
   //       now*=-(j+1);
   //       now%=mod;
   //    }
   // }
   // for(int i=n;i>=1;i--)
   //    x[i]=x[i-1]*niyuan(i)%mod;
   // int ans=0;
   // for(int i=1;i<=n;i++){
   //    //cout<<"x[i]="<<x[i]<<endl;
   //    ans+=x[i]*powmod(vl,i)%mod;
   //    ans%=mod;
   // }
   // cout<<ans<<endl;
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