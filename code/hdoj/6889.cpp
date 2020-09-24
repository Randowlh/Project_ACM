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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int N=1000010;
const int maxn = 510000;
int prime[N], id1[N], id2[N], flag[N], ncnt, m;
ll g[N], sum[N], a[N], T, n;
inline int ID(ll x) {
        return x <= T ? id1[x] : id2[n / x];
}
inline ll calc(ll x) {
    return x * (x + 1) / 2 - 1;
}
inline ll f(ll x) {
    return x;
}
inline void init() {
    T = sqrt(n + 0.5);
    for (int i = 2; i <= T; i++) {
        if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
        for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (ll l = 1; l <= n; l = n / (n / l) + 1) {
        a[++m] = n / l;
        if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
       g[m] = calc(a[m]);
    }
    for (int i = 1; i <= ncnt; i++) 
        for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++) 
            g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
}
inline ll solve(ll x) {
    if (x <= 1) return x;
    return n = x, init(), g[ID(n)];
}
void work()
{
    int n,k;
    cin>>n>>k;
    n%=k;
    int t=(n+1)/2;
    int ans=((n+1)*(n+2)-1-(t)*(t+1))%k;   
    ans=(ans+k)%k;
    cout<<ans<<endl;
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
cin>>t;
//cin>>t;
while (t--)
{
work();
}
return 0;
}