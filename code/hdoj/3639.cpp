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
int low[5100], dfn[5100],flag[5100];
int vl[5100], du[5100];
bool book[5100];
int belong[5100];
vector<int> mp[5100];
vector<int> mp2[5100];
vector<pair<int, int>> eg;
int n, m;
int cnt, cnt2;
stack<int> s;
int bfs(int x){
    book[x] = 1;
    queue<int> q;
    q.push(x);
    int ans = vl[x];
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for (int i = 0;i<mp2[t].size();i++){
            if(!book[mp2[t][i]]){
                ans += vl[mp2[t][i]];
                book[mp2[t][i]] = 1;
                q.push(mp2[t][i]);
            }
        }
    }
    return ans;
}
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
        vl[cnt2]++;
        while(s.top()!=x){
            belong[s.top()] = cnt2;
            flag[s.top()] = 0;
            vl[cnt2]++;
            s.pop();
        }
        s.pop();
        flag[x] = 0;
    }
}
int tt = 0;
void work()
{
    tt++;
    cnt = cnt2 = 0;
    rd(n), rd(m);
    eg.clear();
    for (int i = 1; i <= n;i++)
        mp[i].clear(), vl[i]=book[i] =dfn[i]=du[i]=0,mp2[i].clear();
    int u, v;
    for (int i = 0; i < m;i++)
        rd(u), rd(v), mp[u+1].push_back(v+1),eg.push_back(make_pair(u+1,v+1));
    for (int i = 1; i <= n;i++)
        if(!dfn[i])
            tarjan(i);
    for (int i = 0; i < eg.size(); i++)
        if(belong[eg[i].first]^belong[eg[i].second]){
            mp2[belong[eg[i].second]].push_back(belong[eg[i].first]);
            du[belong[eg[i].first]]++;
           // cout << belong[eg[i].second] << "->" << belong[eg[i].first] << endl;
        }
    int ma = 0;
    set<int> mix;
    for (int i = 1; i <= cnt2;i++){
        if(!du[i]){
         //   cout << "i=" << i << endl;
            for (int j = 1; j <= cnt2;j++)
                book[j] = 0;
            int t=bfs(i)-1;
            if(ma<t){
                ma = t;
                mix.clear();
                mix.insert(i);
            }else if(ma==t){
                mix.insert(i);
            }
        }
    }
        printf("Case %lld: %lld\n", tt, ma);
        vector<int> aa;
        for (int i = 1; i <=n;i++){
            if(mix.count(belong[i]))
                aa.push_back(i-1);
        }
        for (int i = 0; i < aa.size()-1;i++){
            printf("%lld ", aa[i]);
        }
        printf("%lld\n",aa[aa.size()-1]);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t = 1;
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}