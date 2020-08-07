#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#pragma GCC optimize(2)
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
const double delta=0.993;
#define MAX_TIME 940 
//mt19937 myrand(time(0));
//uniform_int_distribution<int> randint {-down, up};
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int __int128
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n,m;
int ans=0;
int date[100];
int dp[100][100];
void work()
{
  
    for(int i=1;i<=n;i++)
        rd(date[i]);
    memset(dp,0,sizeof(dp));
    for(int len=n-2;len>=0;len--)
        for(int i=1;i+len<=n;i++){
            MAX(dp[i][i+len],dp[i-1][i+len]+date[i-1]*((int)1<<(n-len-1)));
            MAX(dp[i][i+len],dp[i][i+len+1]+date[i+len+1]*((int)1<<(n-len-1)));
        }
    int mx=0;
    for(int i=1;i<=n;i++)
    MAX(mx,dp[i][i]+date[i]*((int)1<<(n)));
    ans+=mx;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    rd(t);
    //cin>>t;
      rd(n);
    while (t--)
    {
        work();
    }
    vector<signed> aa;
    while(ans){
        aa.push_back(ans%10);
        ans/=10;
    }
    if(aa.empty()){
    cout<<0<<endl;
    return 0;
    }
    reverse(aa.begin(), aa.end());
    for(int i=0;i<aa.size(); i++)
    cout<<aa[i];
    cout<<endl;
    return 0;
}