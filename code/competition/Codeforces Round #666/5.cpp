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
int n,r1,r2,r3,d;
int date[1100000];
int a[1100000],b[1100000];
int dp[1100000];
void work()
{ 
   rd(n),rd(r1),rd(r2),rd(r3),rd(d);
   int tol=0;
   for(int i=1;i<=n;i++)
      rd(date[i]);   
   for(int i=1;i<=n;i++){
      a[i]=r1*date[i]+r3;
      b[i]=min((date[i]+2)*r1,r1+r2);
   }
   dp[0]=0;
   for(int i=1;i<=n;i++)
      dp[i]=llinf;
   for(int i=1;i<=n;i++){

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