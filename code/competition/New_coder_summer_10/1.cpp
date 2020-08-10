#include <bits/stdc++.h>
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
struct Edges{
    int w,to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
int mp[310][310];
int n;
void work()
{
    rd(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(j%2&&i%2)
            mp[i][j]=1;
            else mp[i][j]=0;
        }
    int now=2;
    while(now<=n){
    int round=(n/2-1)/now;
        for(int i=0;i<round;i++){
            for(int j=now+2;j<=n;j+=now*2){
                mp[i*now*2+2][j]=1;
                mp[j][i*now*2+2]=1;
                cout<<"now="<<now<<endl;
                cout<<j<<' '<<i*now*2+2<<endl; 
            }
        }
        now*=2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        printf("%lld",mp[i][j]);
        printf("\n");
    }
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
    while (t--)
    {
        work();
    }
    return 0;
}