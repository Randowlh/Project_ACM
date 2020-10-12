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
#define int __int128
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int exgcd(int a, int b, int& x, int& y) {
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
int gcd(int a, int b){ return b ? gcd(b, a % b): a;}
inline int lcm(int a, int b){ return a/gcd(a, b)*b;}
int a[110000],b[110000];
int n;
int excrt(int a[],int b[],int n)
{
    int lc=1;
    for(int i=1;i<=n;i++)
        lc=lcm(lc,a[i]);
    for(int i=1;i<n;i++){   
         int p,q,g;
        g=exgcd(a[i],a[i+1],p,q);
        int k=(b[i+1]-b[i])/g;
        q=-q;p*=k;q*=k;
        b[i+1]=a[i]*p%lc+b[i];
        b[i+1]%=lc;
        a[i+1]=lcm(a[i],a[i+1]);
    }
    return (b[n]%lc+lc)%lc;
}
signed main()
{

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
    rd(n);
    for(int i=1;i<=n;i++)
int t = 1;
    int n;
}
wt(excrt(a,b,n));
        rd(a[i]),rd(b[i]);
pt('\n');
//cin>>t;
while (t--)
{
}
return 0;