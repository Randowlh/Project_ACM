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
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
inline int powmod(int a,int b,int mod){
    int res=1;
    int now=a;
    while(b){
        if(b&1)
            res=res*now%mod;
        now=now*now%mod;
        b>>=1;
    }
    return res;
}
inline int niyuan(int x, int mod) { x%=mod; return powmod(x, mod - 2,mod); }
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
void work()
{
    int tol[4],a[4],t[4],m[4],n,d,t2[4];
    m[1]=23;
    m[2]=28;
    m[3]=33;
    cin>>n;
    int cnt=0;
    while(cin>>a[1]>>a[2]>>a[3]>>d,a[1]>=0){
        cnt++;
        tol[1]=tol[2]=tol[3]=m[1]*m[2]*m[3];
        for(int i=1;i<=3;i++)
            tol[i]/=m[i];
        int aa=0,tmp;
        for(int i=1;i<=3;i++){
            t[i]=niyuan(tol[i],m[i]);
            exgcd(tol[i],m[i],t2[i],tmp);
        }
        for(int i=1;i<=3;i++)
            aa+=a[i]*tol[i]*t[i];
        aa%=tol[1]*m[1];
        while(aa<=d)
            aa+=tol[1]*m[1];
        cout<<"Case "<<cnt<<": the next triple peak occurs in "<<aa-d<<" days."<<endl;
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