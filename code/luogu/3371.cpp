#include <iostream>
#include <cstring>
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
const ll llinf = (1<<31)-1;
struct Edges{
    int w,to,next;
}edge[5100000];
struct qnode{
    int v,dis;
    qnode(int a=0,int b=0):v(a),dis(b){}
    bool operator<(const qnode &a)const{
        return dis>a.dis;
    }
};
int head[110000];
int ecnt=0;
void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
int dis[110000];
int flag[110000];
int n,m,s;
void dij(){
    for(int i=1;i<=n;i++)
        dis[i]=llinf,flag[i]=0;
    dis[s]=0;
    priority_queue<qnode> q;
    q.push(qnode(s,0));
    while(!q.empty()){
        int tt=q.top().v;
        q.pop();
        if(flag[tt])
        continue;
        for(int j=head[tt];j;j=edge[j].next){
            int &t=edge[j].to;
            if(dis[t]>dis[tt]+edge[j].w)
                dis[t]=dis[tt]+edge[j].w,q.push(qnode(t,dis[t]));
        }
        flag[tt]=1;
    }
}
void work()
{
    rd(n),rd(m),rd(s);
    int u,v,w;
    for(int i=0;i<m;i++)
    rd(u),rd(v),rd(w),add(u,v,w);
    dij();
    for(int i=1; i <= n; i++)
    printf("%lld ",dis[i]);
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