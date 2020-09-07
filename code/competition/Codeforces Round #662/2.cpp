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
map<int,int> M;
int tw;
int fo;
void work()
{
    M.clear();
    int n;
    rd(n);
    int tt;
    for(int i=0;i<n;i++){
        rd(tt);
        M[tt]++;
        if(M[tt]%2==0){
            tw++;
        }
        if(M[tt]%4==0){
            tw-=2;
            fo++;
        }
    }
    int  m;
    rd(m);
    char opt; 
    for(int i=0;i<m;i++){
        cin>>opt>>tt;
        if(opt=='+'){
            M[tt]++;
            if(M[tt]%2==0){
                tw++;
            }
            if(M[tt]%4==0){
                tw-=2;
                fo++;
            }
        }else{
            M[tt]--;
            if(M[tt]%4==3){
                tw++;
                fo--;
            }
            if(M[tt]%2==1){
                tw--;
            }
        }
        if(fo>=2){
            cout<<"YES"<<endl;
        }else if(fo&&tw>=2){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }

}
signed main()
{
#ifndef ONLINE_JUDGE
  //  freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}