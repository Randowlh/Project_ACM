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
#define int long long
const int maxn=51000;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node{
    int u,v,w;
    node(int a = 0, int b = 0, int c = 0):u(a),v(b),w(c){}
    bool operator<(node &a){
        return w<a.w;
    }
};
int n,m;
vector<int> mp[maxn];
int flag[maxn],low[maxn],dfn[maxn],belong[maxn],date[maxn],cost[maxn];
stack<int> s;
int cnt,cnt2;
vector<node> eg;
int find(int x){
    if(x==date[x])
    return x;
    else return date[x]=find(date[x]);
}
void merge(int x,int y){
    int l=find(x),r=find(y);
    date[l]=r;
}
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    flag[x]=1;
    s.push(x);
    for(int i=0;i<mp[x].size();i++){
        int &t = mp[x][i];
        if(!dfn[t]){
            tarjan(t);
            low[x]=min(low[x],low[t]);
        }else if(flag[t])
            low[x]=min(low[x],dfn[t]);
    }
    if(low[x]==dfn[x]){
        belong[x]=++cnt2;
        while(s.top()!=x){
            belong[s.top()]=cnt2;
            flag[s.top()]=0;
            s.pop();
        }
        flag[x]=0;
        s.pop();
    }
}
void work()
{
    while(scanf("%lld%lld", &n, &m)!=EOF){
        cnt=cnt2=0;
        for(int i=0;i<=n;i++)
        mp[i].clear(),dfn[i]=0;
        eg.clear();
        int w,u,v;
        for(int i=0;i<m;i++)
        rd(u), rd(v),rd(w),mp[u].push_back(v),eg.push_back(node(u,v,w));
        for(int i=0;i<n;i++)
            if(!dfn[i])
            tarjan(i);
        for(int i=0;i<=cnt2;i++){
            cost[i]=llinf;
        }
        cost[belong[0]]=0;
        int ans=0;
        for(int i=0;i<eg.size();i++){
            if(belong[eg[i].u]^belong[eg[i].v])
            cost[belong[eg[i].v]]=min(cost[belong[eg[i].v]],eg[i].w);
        }
        for(int i=1;i<=cnt2;i++)
            ans+=cost[i];
        printf("%lld\n",ans);
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}