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
const ll llinf = (9223372036854775807>>1)-100;
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
class mint{
    public:
    int powmod(int a,int b) {int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
    int  n;
    mint() : n(0) { ; }
    mint(ll m) : n(m)
    {
        if (n >= mod)
            n %= mod;
        else if (n < 0)
            n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
    inline mint operator=(mint a){n=a.n;return n;}
    inline bool operator==(mint a){return n==a.n;}
    inline bool operator!=(mint a){return n!=a.n;}
    inline bool operator<(mint a){return n<a.n;}
    inline bool operator>(mint a){return n>a.n;}
    inline bool operator<=(mint a){return n<=a.n;}
    inline bool operator>=(mint a){return n>=a.n;}
    inline mint operator+(mint a){int res=n+a.n;if(res>=mod)res-=mod; return res;}
    inline mint operator-(mint a){int res=n-a.n;if(res<0)res+=mod;return res;}
    inline mint operator*(mint a){int res=n*a.n%mod;return res;}
    inline mint operator/(mint a){int res=n*niyuan(a.n,mod)%mod;return res;}
    inline mint operator+=(mint a){*this=*this+a;return *this;}
    inline mint operator-=(mint a){*this=*this-a;return *this;}
    inline mint operator*=(mint a){*this=*this*a;return *this;}
    inline mint operator/=(mint a){*this=*this/a;return *this;}
    inline mint operator++(){n++;n%=mod;return n;}
};
ll powmod(ll a, ll n, ll m = mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}
struct node{
    mint a,b;
}dp[210000][3];
mint ans[210000];
string tmp;
void work()
{
    int n;
    cin>>n;
    cin>>tmp;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(tmp[i]=='?')
            cnt++;
    }
    for(int i=1;i<=n;i++){
        if(tmp[i-1]=='a')
            dp[i][0].a=1;
        if(tmp[i-1]=='b'){
            dp[i][0].b+=dp[i-1][0].a;
            dp[i][1].b+=dp[i-1][1].a;
        }
        if(tmp[i-1]=='c'){
            if(dp[i-1][0].b)
            ans[i]+=dp[i-1][0].b*(mint)powmod(3,cnt);
            if(dp[i-1][1].b)
            ans[i]+=dp[i-1][1].b*(mint)powmod(3,cnt-1);
            if(dp[i-1][2].b)
            ans[i]+=dp[i-1][2].b*(mint)powmod(3,cnt-2);
        }
        if(tmp[i-1]=='?'){
            dp[i][1].a+=1;
            dp[i][1].b+=dp[i-1][0].a;
            dp[i][2].b+=dp[i-1][1].a;
            if(dp[i-1][0].b)
            ans[i]+=dp[i-1][0].b*(mint)powmod(3,cnt-1);
            if(dp[i-1][1].b)
            ans[i]+=dp[i-1][1].b*(mint)powmod(3,cnt-2);
            if(dp[i-1][2].b)
            ans[i]+=dp[i-1][2].b*(mint)powmod(3,cnt-3);
        }
        ans[i]+=ans[i-1];
        for(int j=0;j<3;j++){
            dp[i][j].a+=dp[i-1][j].a;
            dp[i][j].b+=dp[i-1][j].b;
        }
    }
    cout<<ans[n]<<endl;
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