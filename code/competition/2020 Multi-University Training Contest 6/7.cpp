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
inline int gcd(int a,int b){ return b ? gcd(b, a % b) : a;}
int n,m;
int u[11000],v[11000],w[11000];
int lk[110][110];
int tmp[3][3]={0,0,0,
            0,1,-1,
            0,1,1};
int calc()
{
    int fan=0;
    int cheng=1;
    for(int i=1;i<=n;i++){
        int mix=-1;
        for(int j=i;j<=n;j++){
            if(tmp[j][i]){
                mix=i;
            }
        }
        if(mix==-1)
        return 0;
        if(mix!=i){
            for(int j=1;j<=n;j++)
                swap(tmp[i][j],tmp[mix][j]);
            fan^=1;
        }
        for(int j=i+1;j<=n;j++){
            if(!tmp[j][i])
                continue;
            int a=tmp[j][i]/gcd(tmp[j][i],tmp[mix][i]);
            int b=tmp[mix][i]/gcd(tmp[j][i],tmp[mix][i]);
            cheng=cheng*b%mod;
            for(int k=1;k<=n;k++){
                tmp[i][k]*=b;
                tmp[i][k]%=mod;
                tmp[i][k]-=tmp[mix][k]*a;
                (tmp[i][k]+=mod)%mod;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=tmp[i][i];
        ans%=mod;
    }
    ans*=cheng;
    ans%=mod;
    if(fan)
    ans=-ans;
    return ans;
}
void work()
{
    n=2;
    // rd(n),rd(m);
    // for(int i=0;i<m;i++)
    //     rd(u),rd(v),rd(w);
    // vector<int> a;
    // for(int i=0;i<31;i++){
    //     int t=1<<i;
    //     memset(lk,0,sizeof(lk));
    //     for(int j=0;j<m;j++)
    //     if(w[i]&t)
    //         lk[u[i]][v[i]]++;
    //     int cheng=1;
    //     for(int i=1;i<=n;i++)
    //         for(int j=1;j<=n;j++){
    //             if(lk[i][j])
    //             cheng*=lk[i][j];
    //         }
        
    cout<<calc()<<endl;
    // }
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
    while (t--)
    {
        work();
    }
    return 0;
}