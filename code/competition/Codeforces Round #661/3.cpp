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
    rd(n);
    vector<int> v;
    int tmp;
    for(int i=0;i<n;i++){
        rd(tmp),v.push_back(tmp);
    }
    if(n<=3){
        if(n<2)
        cout<<0<<endl;
        else
        cout<<1<<endl;
        return;
    }
    int flag[53];
    sort(v.begin(),v.end());
    int ans=0;
    for(int now=v[0]+v[1];now<=v[v.size()-1]+v[v.size()-2];now++){
        int tans=0;
        memset(flag, 0, sizeof(flag));
        for(int i=0;i<n-1;i++){
            if(flag[i])
            continue;
            for(int j=i+1;j<n;j++)
                if(!flag[j]&&v[i]+v[j]==now){
                flag[i]=flag[j]=1,tans++;
                break;
                }
        }
        ans=max(ans,tans);
    }
    printf("%lld\n",ans);
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