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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[20][1<<17];
int lk[20];
int vl[20];
int n;
int calc(int i){
    int ans=0;
    while(i){
        if(i&1)
        ans++;
        i>>=1;
    }
    return  ans;
}
int cnt=0;
void work()
{
    cnt++;
    printf("Case #%lld:\n",cnt);
    rd(n);
    for(int i=0;i<n;i++)
        rd(vl[i]),rd(lk[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
        dp[i][j]=-llinf;
    for(int i=0; i<n; i++)
		if(lk[i]==-1 || lk[i]==0)
			dp[i][1<<i] = 0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(dp[j][i]==-llinf)
                continue;
            for(int k=0;k<n;k++){
                if(i&(1<<k)||j==k)
                    continue;
                if(lk[k]==-1||lk[k]==calc(i)){
                    dp[k][i|(1<<k)]=max(dp[k][i|(1<<k)],dp[j][i]+vl[j]*vl[k]);
                }
            }
        }
    }
    int ans=-llinf;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][(1<<n)-1]);
    }
    printf("%lld\n",ans);
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