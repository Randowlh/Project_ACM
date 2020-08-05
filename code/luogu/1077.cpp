#include <iostream>
#include<cstring>
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
    x=0;char o,f=(char)1;
    while(o=getchar(),o<'0')if(o=='-')f=-f;
    do x=(x<<3)+(x<<1)+(o^'0');
    while(o=getchar(),o>'/');
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
const ll mod = 1000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n,m;
int dp[110][110];
int date[110];
void work()
{
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
        rd(date[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=date[i]&&j+k<=m;k++)
            dp[i][j+k]+=dp[i-1][j],dp[i][j+k]%=mod;
        }
    }
    printf("%lld\n",dp[n][m]);
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