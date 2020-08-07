#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <queue>
#include <ciso646>
#include <random>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <complex>
#include <numeric>
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
int dp[110][110];
int root[110][110];
vector<int> ans;
void dfs(int l,int r){
    if(l==r)
    return;
    if(l+1==r){
        ans.push_back(l);
        return;
    }
    int now=root[l][r];
    ans.push_back(now);
    dfs(l,now);
    dfs(now+1,r);
}
void work()
{
    rd(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=1;
    for(int i=1;i<=n;i++)
        rd(dp[i][i+1]);
    for(int len=2;len<=n;len++)
        for(int i=1;i+len<=n+1;i++)
            for(int j=i;j<i+len;j++){
                if(dp[i][i+len]<dp[i][j]*dp[j+1][i+len]+dp[j][j+1])
                dp[i][i+len]=dp[i][j]*dp[j+1][i+len]+dp[j][j+1],root[i][i+len]=j;
            }
    printf("%lld\n",dp[1][n+1]);
    dfs(1,n+1);
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}