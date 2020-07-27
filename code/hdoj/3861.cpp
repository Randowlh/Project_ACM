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
const int maxn = 5100;
vector<int> mp[maxn];
int dfn[maxn], low[maxn],flag[maxn],belong[maxn];
int ans =0;
int cnt=0,cnt2=0;
stack<int> s;
vector<pair<int,int> > eg;
class DC
{
public:
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    int book[10100];
    int cur[10100];
    int depth[10100];
    int n, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[10100];
    int bfs(int s, int t)
    {
        memset(book, 0, sizeof(book));
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            for(int i=0;i<=n;i++)
            cur[i]=0;
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
    void init(int nn,int ss,int tt){
        n=nn,s=ss,t=tt;
        for(int i=0;i<=n;i++)
        mp[i].clear();
        edge.clear();
    }
} fl;
void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    flag[x]=1;
    s.push(x);
    for(int i=0;i<mp[x].size();i++){
        int& t=mp[x][i];
        if(!dfn[t]){
            tarjan(t);
            low[x]=min(low[x], low[t]);
        }else if(flag[t])
            low[x]=min(low[x],dfn[t]);
    }
    if(low[x]==dfn[x]){
        ans++;
        belong[x]= ++cnt2;
        while(s.top()!=x){
            flag[s.top()]=0;
            belong[s.top()]=cnt2;
            s.pop();
        }
        s.pop();
        flag[x]=0;
    }
}
void work()
{
    ans =cnt=cnt2=0;
    int n, m;
    rd(n), rd(m);
    eg.clear();
    rep(i, 1, n)
        mp[i].clear(),dfn[i] = 0;
    int u, v;
    rep(i, 1, m)
        rd(u),rd(v), mp[u].push_back(v),eg.push_back(make_pair(u, v));
    rep(i,1,n)
        if(!dfn[i])
        tarjan(i);
    fl.init(cnt2*2+10,0,cnt2*2+4);
    rep(i,1,cnt2)
        fl.add_edge(0,i,1);
    rep(i,cnt2+1,cnt2*2)
        fl.add_edge(i,cnt2*2+4,1);
    for(int i=0;i<eg.size(); i++)
        if(belong[eg[i].first]^belong[eg[i].second])
        fl.add_edge(belong[eg[i].first],belong[eg[i].second]+cnt2,1);
    printf("%lld\n",cnt2-fl.Dinic());
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1;
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}