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
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int maxm= 5100;
vector<int> mp[2][11000];
int n;
struct low_cost_flow
{
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cost;
        Edge(int fr = 0, int t = 0, int f = 0, int cc = 0) : from(fr), to(t), flow(f), cost(cc) {}
    };
#define inf 0x3f3f3f3f
#define maxn 1500
    int book[maxn];
    int dis[maxn];
    int n, s, t, ans;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void add_edge(int x, int y, int flow, int cost)
    {
        edge.push_back(Edge(x, y, flow, cost));
        edge.push_back(Edge(y, x, 0, -cost));
        mp[x].push_back(edge.size() - 2);
        mp[y].push_back(edge.size() - 1);
    }
    bool spfa()
    {
        for (int i = 0; i <= n + 100; i++)
        {
            dis[i] = inf;
            book[i] = 0;
        }
        dis[t] = 0;
        book[t] = 1;
        deque<int> q;
        q.push_back(t);
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            for (int i = 0; i < mp[now].size(); i++)
            {
                int to = edge[mp[now][i]].to;
                if (edge[mp[now][i] ^ 1].flow && dis[to] > dis[now] - edge[mp[now][i]].cost)
                {
                    dis[to] = dis[now] - edge[mp[now][i]].cost;
                    if (!book[to])
                    {
                        book[to] = 1;
                        if (!q.empty() && dis[to] < dis[q.front()])
                            q.push_front(to);
                        else
                            q.push_back(to);
                    }
                }
            }
            book[now] = 0;
        }
        return dis[s] < inf;
    }
    int dfs(int x, int flow)
    {
        book[x] = 1;
        if (x == t)
            return flow;
        int used = 0, a;
        for (int i = 0; i < mp[x].size(); i++)
        {
            int to = edge[mp[x][i]].to;
            if (!book[to] && edge[mp[x][i]].flow > 0 && dis[x] - edge[mp[x][i]].cost == dis[to])
            {
                a = dfs(to, min(flow - used, edge[mp[x][i]].flow));
                if (a)
                    ans += a * edge[mp[x][i]].cost, edge[mp[x][i]].flow -= a, edge[mp[x][i] ^ 1].flow += a, used += a;
                if (used == flow)
                    break;
            }
        }
        return used;
    }
    void init(int tn,int ts,int tt)
    {
        for (int i = 0; i <= tn+10; i++)
            mp[i].clear();
        edge.clear();
        n = tn;
        s = ts;
        t = tt;
        ans = 0;
    }
    int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            for (int i = 0; i <= n + 200; i++)
                book[i] = 0;
            flow += dfs(s, inf);
        }
        return flow;
    }
};
vector<int> primes;
bool is_prime[111000];
void euler()
{
    is_prime[1] = 1;
    for (int i = 2; i < 110000; i++)
    {
        if (!is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < 110000; j++)
        {
            is_prime[i * primes[j]] = 1;
            if ((i % primes[j]) == 0)
                break;
        }
    }
}

int hsh[2][11000];
int dp[510][510];
int treehash(int now,int flag){
    int sz=1;
    hsh[flag][now]=1;
    for(int i=0;i<mp[flag][now].size();i++){
        int tmp=treehash(mp[flag][now][i],flag);
        sz+=tmp;
        hsh[flag][now]+=hsh[flag][mp[flag][now][i]]*primes[tmp];
    }
    hsh[flag][now]%=mod;
    return sz;
}
int calc(int a,int to){
    if(dp[a][to]!=-1)
        return dp[a][to];
    vector<pair<int,int>> vv1,vv2;
    int ans;
    if(a!=to)
    ans=1;
    else
    ans=0;
    for(int i=0;i<mp[0][a].size();i++)
        vv1.push_back(make_pair(hsh[0][mp[0][a][i]],mp[0][a][i]));
    for(int i=0;i<mp[1][to].size(); i++)
        vv2.push_back(make_pair(hsh[1][mp[1][to][i]],mp[1][to][i]));
    if(!vv1.size()){
        dp[a][to]=ans;
        return ans;
    }
    sort(vv1.begin(),vv1.end());
    sort(vv2.begin(),vv2.end());
    int now=llinf;
    int begin=0;
    int ed=0;
    for(int i=0;i<vv1.size();i++){
        if(now==vv1[i].first){
            ed=i;
        }else{
            now=vv1[i].first;
            if(false){
            low_cost_flow tt;
            int dis=ed-begin+1;
            tt.init(dis*2+50,0,dis*2+32);
            for(int j=begin;j<=ed;j++){
                tt.add_edge(0,j-begin+1,1,0);
                tt.add_edge((dis)+j-begin+2,(dis)*2+32,1,0);
            }
            for(int j=begin;j<=ed;j++)
                for(int k=begin;k<=ed;k++){
                    tt.add_edge(j-begin+1,dis+k-begin+2,1,calc(vv1[j].second,vv2[k].second));
                }
            tt.cost_flow();
            ans+=tt.ans;
            }else{
                cout<<begin<<' '<<ed<<endl;
                 ans+=calc(vv1[begin].second,vv2[begin].second);
            }
            begin=i;
            ed=i;
        }
    }
    cout<<">>>"<<begin<<' '<<ed<<endl;
    //cout<<">>>"<<begin<<' '<<ed<<endl;
    puts("-1");
    if(begin!=ed){cout<<">>>"<<begin<<' '<<ed<<endl;
    cout<<"jadhkfbsakjdfbnsadkjlfgksadfhkj"<<endl;
    low_cost_flow tt;
    int dis=ed-begin+1;
    tt.init(dis*2+50,0,dis*2+32);
        for(int j=begin;j<=ed;j++){
            tt.add_edge(0,j-begin+1,1,0);
            tt.add_edge((dis)+j-begin+2,(dis)*2+32,1,0);
        }
        for(int j=begin;j<=ed;j++)
            for(int k=begin;k<=ed;k++)
                tt.add_edge(j-begin+1,dis+k-begin+2,1,calc(vv1[j].second,vv2[k].second));
            tt.cost_flow();
            ans+=tt.ans;
    }else{
        cout<<"??"<<endl;
        ans+=calc(vv1[begin].second,vv2[begin].second);
    }
    dp[a][to]=ans;
    return ans;
}
void work()
{
    memset(dp,-1,sizeof dp);
    rd(n);
    int a;
    int roota,root;
    for(int i=1;i<=n;i++){
        rd(a);
        if(a)
        mp[0][a].push_back(i);
        else root=i;
    }
    for(int i=1;i<=n;i++){
        rd(a);
        if(a)
        mp[1][a].push_back(i);
        else roota=i;
    }
    treehash(root,0);
    treehash(roota,1);
    set<int> s;
    // for(int i=1;i<=n;i++){
    //     cout<<hsh[1][i]<<" "<<hsh[0][i]<<endl;
    //     s.insert(hsh[1][i]);
    // }
    cout<<s.size()<<endl;
    int ans=calc(root,roota);
    printf("%lld\n",ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    euler();
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}