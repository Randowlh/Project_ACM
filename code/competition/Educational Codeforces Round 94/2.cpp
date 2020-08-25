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
    int p,f,tp,tf;
    cin>>p>>f;
    if(p>f)
    swap(p, f);
    int ws,wp,tws,twp;
    int cs,cp,tcs,tcp;
    cin>>cs >> cp;
    cin>>ws>>wp;
    tcs= cs;
    tcp=cp;
    tws=ws;
    twp=wp;
    tf=f;
    tp=p;
    int ans=0,aa=0;
    if(ws>wp){
        swap(ws,wp);
        swap(cs,cp);
    }
    int dis=wp-ws;
    ans+=min(cs,p/ws);
    int tans=ans;
    p-=tans*ws;
    cs-=tans;
    if(p>=wp){
        int t=min(cp,p/wp);
        ans+=t;
        p-=t*wp;
        cp-=t;
    }
    //cout<<"p="<<p<<endl;
    if(p&&dis){
        int t=min(tans,min(cp,p/dis));
        cs+=t;
        cp-=t;//min(tans,min(cp,p/dis));
    }
    ans+=min(f/ws,cs);
    f-=min(f/ws,cs)*ws;
    ans+=min(f/wp,cp);
    aa=ans;
    /////////////////////////////////////////
    ans=0;
    cs= tcs;
    cp=tcp;
    ws=tws;
    wp=twp;
    f=tp;
    p=tf;
    /////////////////////////////////////
    dis=wp-ws;
    ans+=min(cs,p/ws);
    tans=ans;
    p-=tans*ws;
    cs-=tans;
    if(p>=wp){
        int t=min(cp,p/wp);
        ans+=t;
        p-=t*wp;
        cp-=t;
    }   
    //cout<<"p="<<p<<endl;
    if(p&&dis){
        int t=min(tans,min(cp,p/dis));
        cs+=t;
        cp-=t;//min(tans,min(cp,p/dis));
    }
     ans+=min(f/ws,cs);
    f-=min(f/ws,cs)*ws;
    ans+=min(f/wp,cp);
    cout<<max(aa,ans)<<endl;
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
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}