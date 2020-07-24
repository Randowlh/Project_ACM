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
int low[11000];
vector<int> mp[11000];
int dfn[11000];
int flag[11000];
int cnt = 0;
int ans = 0;
int n, m;
stack<int> s;
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
        ans++;
        while(s.top()!=x){
            flag[s.top()] = 0;
            s.pop();
        }
        s.pop();
        flag[x] = 0;
    }
}
void work()
{ 
    while(scanf("%lld%lld", &n, &m)!=EOF,n||m){
        ans=cnt = 0;
        for (int i = 0; i <= n;i++)
            mp[i].clear(), dfn[i] = 0,flag[i]=0;
        int u, v;
        for (int i = 0;i<m;i++){
            rd(u), rd(v);
        if (u!=v)
            mp[u].push_back(v);
        }
        for (int i = 1; i <= n;i++)
            if(!dfn[i])
                tarjan(i);
        if (ans == 1)
            printf("Yes\n");
        else 
            printf("No\n");
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