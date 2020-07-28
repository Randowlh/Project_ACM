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
int dp[1<<20];
int lf[1<<20];
int cost[20];
int vl[20];
vector<int> mp[20];
bool ck(int i,int j){
    for(int k=0;k<mp[j].size();k++){
        if((1<<(mp[j][k]-1))&i)
        continue;
        else
        return false;
    }
    return true;
}
void work()
{
    int n,e;
    rd(n), rd(e);
    for(int i=0;i<n;i++)
        rd(vl[i]),mp[i].clear();
    for(int i=0;i<n;i++)
        rd(cost[i]);
    for(int i=0;i<n;i++){
        int tt,tmp;
        rd(tt);
        for(int j=0;j<tt;j++)
            rd(tmp),mp[i].push_back(tmp);
    }
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    lf[0]=e;
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]==-1)
        continue;
        ans=max(ans,dp[i]);
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            continue;
            if(ck(i,j)&&lf[i]>=cost[j]){
                dp[i|(1<<j)]=dp[i]+vl[j];
                lf[i|(1<<j)]=lf[i]-cost[j];
            }
        }
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