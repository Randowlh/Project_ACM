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
const ll mod = (1 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 505;
int dp[2][maxn][maxn];
char mp[maxn][maxn];
int n;
void work()
{   
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    dp[0][1][n]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i+1;j++)
            for(int k=n;k>=n-i;k--){
                if(mp[j][i-j+2]==mp[k][n-(i-(n-k))]){
                    dp[1][j][k]=(dp[0][j][k]+dp[0][j-1][k]+dp[0][j][k+1]+dp[0][j-1][k+1])%mod;
                }else dp[1][j][k]=0;
            }
        for(int j=1;j<=i+1;j++)
            for(int k=n;k>=n-i;k--){
                    dp[0][j][k]=dp[1][j][k];
            }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[1][i][i]; 
        ans%=mod;
    }  
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}