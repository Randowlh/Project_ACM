#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
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
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 223372036854775807;
int dp[18][1<<18];
int mp[20][20];
void work()
{
    int n,m;
    rd(n),rd(m);
    int u,v,w;
    memset(mp,inf,sizeof(mp));
    for(int i=0;i<n;i++)
    mp[i][i]=0;
    for(int i=0;i<m;i++)
    rd(u),rd(v),rd(w),mp[u-1][v-1]=min(mp[u-1][v-1],w),mp[v-1][u-1]=mp[u-1][v-1];
    memset(dp,inf,sizeof dp);
    dp[0][0]=0;
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
    for(int cur=0;cur<(1<<n);cur++)
        for(int i=0;i<n;i++)
            if(dp[i][cur]!=inf){
            for(int j=0;j<n;j++){
                   dp[j][cur|1<<j]=min(dp[j][cur|1<<j],dp[i][cur]+mp[i][j]);
           }
            }
    printf("%d\n",dp[0][(1<<n)-1]);
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
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}