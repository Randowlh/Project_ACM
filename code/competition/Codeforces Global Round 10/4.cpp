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
void work()
{
    int n;
    string tmp;
    cin>>n>>tmp;
    int tr=0,tl=0;
    for(int i=0;i<n;i++){
        if(tmp[i]=='R')
        tr++;
        else tl++;
    }
    if(!tr||!tl){
        cout<<n/3+(n%3>0)<<endl;
        return ;
    }
    char now=tmp[0];
    int flag=0;
    int cnt=0;
    int i=0;
    int ans=0;
    int ff=0;
    while(!ff){
        if(i-1000000==flag){
            ff=1;
        }        
        if(now!=tmp[i]&&flag==0){
            cnt=1;
            flag=i-1000000;
            now=tmp[i];
            i=(i+1)%n;
            continue;
        }
        if(now!=tmp[i]){
            cnt-=2;
            if(cnt>0){
                ans+=(cnt/3+(cnt%3>0));
            }
            now=tmp[i];
            cnt=1;
        }else cnt++;
        i=(i+1)%n;
    }
    if(!flag){
        cout<<n/3+(n%3>0)<<endl;
    }else{
        cout<<ans<<endl;
    }
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