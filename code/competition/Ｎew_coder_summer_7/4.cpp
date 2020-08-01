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
ll mod = (1 ? 1000000007 : 998244353);
inline ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll niyuan(int a){return powmod(a,mod-2);}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int ans[5100];
int akk[5100];
int jc[5100];
int C(int a,int k) 
{  
    if(a==k)
    return 1;
    int res = 1;  
    while(a && k)  
    {  
        int a1 = a % mod;
        int b1 = k % mod;  
        if(a1 < b1) return 0;
        res = res*jc[a1]*powmod(jc[b1]*jc[a1-b1]%mod,mod-2)%mod;
        a /= mod;  
        k /= mod;  
    }  
    return res;  
}  

void work()
{
    int n,mod;
    rd(n), rd(mod);
    ans[1]=0;
    akk[1]=0;
    jc[1]=1;
    for(int i=2;i<1005;i++)
        jc[i]=jc[i-1]*i%mod;
    for(int i=2;i<1000;i++){
        akk[i]=(powmod(2,i-1))%mod*jc[i];
        akk[i]%=mod;
        for(int j=1;j<i;j++)
            ans[i]=(ans[i]+(C(i-1,j-1)*akk[j])%mod)%mod;
    } 
    // for(int i=0;i<10;i++)
    // printf("%lld\n",akk[i]);
    int t;
    for(int i=0;i<n;i++){
        rd(t);
        printf("%lld\n",ans[t]);
    }
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