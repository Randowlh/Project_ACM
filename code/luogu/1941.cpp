#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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
#define pc putchar
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf =0x3f3f3f3f;
const int maxm= 1;
const int maxn = 510000;
pair<int,int> rg[11000];
pair<int,int> ud[11000];
int dp[2][1100];
int f[11000];
int n,m,k;
int p,l,h;
inline void work()
{
    register int i,j,k;
    rd(n),rd(m),rd(k);
    for(int i=1;i<=n;i++)
        rd(ud[i].first),rd(ud[i].second);
    for(int i=1;i<=n;i++)
        rg[i].first=0,rg[i].second=m+1;
    for(int i=1;i<=k;i++){
        rd(p),rd(l),rd(h);
        f[p]=1;
        rg[p].first=l;
        rg[p].second=h;
    }
    for(i=1;i<=n;i++)
        f[i]=f[i-1]+f[i];
    register int ff=0,flag=0;
    for(i=1;i<=n;i++){
        ff^=1;
        flag=0;
        for(j=1;j<=m;j++){
            if(j<=rg[i].first||j>=rg[i].second){
                dp[ff][j]=llinf;
                continue;
            }
            dp[ff][j]=llinf;
            if(j+ud[i].second<=m)
                MIN(dp[ff][j],dp[ff^1][j+ud[i].second]);
            int pre=j-ud[i].first;
            int cnt=1;
            while(pre>0){
                MIN(dp[ff][j],dp[ff^1][pre]+cnt);
                pre-=ud[i].first;
                cnt++;
            }
            if(j==m){
            for(k=rg[i-1].first+1;k<rg[i-1].second;k++){
                    MIN(dp[ff][m],dp[ff^1][k]+(1+(m-k)/ud[i].first));
                }
            }
            if(dp[ff][j]!=llinf)
                flag=1;
        }
        if(!flag){
            pc('0'),pc('\n'),wt(f[i-1]),pc('\n');
            return;
        }
    }
    int ans=llinf;
    for(int i=1;i<=m;i++)
        MIN(ans,dp[ff][i]);
    wt(1),pc('\n'),wt(ans),pc('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}