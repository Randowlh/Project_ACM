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
const int maxm= 1;
void work()
{
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
        a[i]-='0';
    int ans=llinf;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++){
            if(i==j)
                continue;
            int flag=0;
            int cnt=0;
            for(int k=0;k<a.size();k++){
                if(flag&&a[k]==j){
                    flag=0;
                    cnt+=2;
                }
                if(!flag&&a[k]==i){
                    flag=1;
                }
            }
            ans=min(ans,(int)a.size()-cnt);
        }
    for(int i=0;i<=9;i++){
        int cnt=0;
        for(int k=0;k<a.size();k++){
            if(a[k]==i)
                cnt++;
        }
        ans=min(ans,(int)a.size()-cnt);
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
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}