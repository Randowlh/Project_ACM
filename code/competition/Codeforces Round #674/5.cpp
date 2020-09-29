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
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
struct node{
    int a,b,c;
}dp[210000];
string tmp;
void work()
{
    int n;
    cin>>n;
    cin>>tmp;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(tmp[i-1]=='a')
            dp[i].a=1;
        if(tmp[i-1]=='b')
            dp[i].b=dp[i-1].a;
        if(tmp[i-1]=='c')
            dp[i].c=dp[i-1].b;
        if(tmp[i-1]=='?'){
            dp[i].a=1;
            dp[i].b=dp[i-1].a;
            dp[i].c=dp[i-1].b;
        }
        dp[i].a+=dp[i-1].a;
        dp[i].b+=dp[i-1].b;
        dp[i].c+=dp[i-1].c;
        dp[i].a%=mod;
        dp[i].b%=mod;
        dp[i].c%=mod;
        cout<<"a "<<dp[i].a<<" b "<<dp[i].b<<" c "<<dp[i].c<<endl;
    }
    cout<<dp[n].c<<endl;
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