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
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n, m;
vector<int> mp[1100];
int low[1100],dfn[1100],flag[1100];
int belong[1100];
int cost[1100];
int cost2[1100];
int du[1100];
vector<pair<int, int>> eg;
stack<int> s;
int  cnt,cnt2;
void tarjan(int x){
    dfn[x] = low[x] = ++cnt;
    flag[x] = 1;
    s.push(x);
    for (int i = 0;i<mp[x].size();i++){
        int &t = mp[x][i];
        if(!dfn[t]){
            tarjan(t);
            low[x] = min(low[x], low[t]);
        }else if(flag[t]){
            low[x] = min(low[x], dfn[t]);
        }
    }
    if(dfn[x]==low[x]){
        int aa = llinf;
        belong[x] = ++cnt2 ;
        while(s.top()!=x){
            belong[s.top()] = cnt2;
            aa = min(aa, cost[s.top()]);
            flag[s.top()] = 0;
            s.pop();
        }
        aa=min(aa, cost[x]);
        cost2[cnt2] = aa;
        s.pop();
        flag[x] = 0;
    }
}
void work()
{
    while(scanf("%lld%lld",&n,&m)!=EOF){
         cnt=cnt2 = 0;
         eg.clear();
        for (int i = 1; i <= n;i++){
            mp[i].clear();
            rd(cost[i]), dfn[i]=du[i] = 0;
        }
        int u, v;
        for (int i = 0; i < m;i++){
            rd(u), rd(v);
            if(u^v)
            mp[u].push_back(v),eg.push_back(make_pair(u,v));
        }
        for (int i = 1; i <= n;i++){
            if(!dfn[i])
                tarjan(i);
        }
        for (int i = 0; i < eg.size(); i++)
        {
            if(belong[eg[i].first]^belong[eg[i].second])
                du[belong[eg[i].second]]++;
        }
        int a1 = 0, a2 = 0;
        for (int i = 1; i <= cnt2;i++)
        if(!du[i])
            a1++, a2 += cost2[i];
        printf("%lld %lld\n",a1,a2);
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
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