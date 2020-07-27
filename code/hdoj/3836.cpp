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
vector<int> mp[210000];
int cnt,cnt2;
int cdu[210000], rdu[210000],belong[210000];
int low[210000], dfn[210000],flag[210000];
vector<pair<int, int>> eg;
stack<int> s;
int n, m;
void tarjan(int x){
    low[x] = dfn[x] = ++cnt;
    s.push(x);
    flag[x] = 1;
    for (int i = 0; i < mp[x].size(); i++){
        int &t = mp[x][i];
        if(!dfn[t]){
            tarjan(t);
            low[x] = min(low[x], low[t]);
        }else if(flag[t])
            low[x] = min(low[x], dfn[t]);
    }
    if(low[x]==dfn[x]){
        belong[x] = ++cnt2;
        while(s.top()!=x){
            belong[s.top()] = cnt2;
            flag[s.top()] = 0;
            s.pop();
        }
        s.pop();
        flag[x] = 0;
    }
}
void work()
{
    while(scanf("%lld%lld", &n, &m)!=EOF){
    cnt2 = cnt = 0;
    for (int i = 0; i <= n;i++){
        mp[i].clear();
        cdu[i] = rdu[i] = flag[i]=dfn[i] = belong[i] = 0;
    }
    eg.clear();
    int u, v;
    for (int i = 0;i<m;i++)
        scanf("%lld%lld", &u, &v), mp[u].push_back(v), eg.push_back(make_pair(u, v));
    for (int i = 1; i <= n;i++)
        if(!dfn[i])
            tarjan(i);
    for (int i = 0;i<eg.size();i++){
        if(belong[eg[i].first]^belong[eg[i].second]){
            rdu[belong[eg[i].second]]++;
            cdu[belong[eg[i].first]]++;
        }
    }
    if(cnt2==1){
        printf("0\n");
        continue;
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cnt2;i++){
        if(!rdu[i])
            ans1++;
        if(!cdu[i])
            ans2++;
    }
    printf("%lld\n", max(ans1,ans2));
    }
}
signed main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}