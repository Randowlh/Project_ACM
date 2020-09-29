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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 11000;
class DC{
public:
    struct Edge
   {
        int from,to,flow,cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    bool book[maxn];
    int cur[maxn],depth[maxn],n, t, s;
    vector<Edge> edge;
    vector<int> mp[maxn];
    int bfs(int s, int t)
    {
        for(int i=0;i<=n;i++)
            book[i]=0;
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
    void init(int ss,int tt,int nn){
        s=ss,t=tt,n=nn;
        for(int i=0;i<=n;i++)
            mp[i].clear();
        edge.clear();
    }
}  fl,fl2;
void work()
{
    int n;
    cin>>n;
    int a[4],b[4];
    cin>>a[1]>>a[2]>>a[3];
    cin>>b[1]>>b[2]>>b[3];
    int tol=a[1]+a[2]+a[3];
    fl.init(1,10,110);
    fl2.init(1,10,110);
    fl.add_edge(1,2,a[1]);
    fl2.add_edge(1,2,a[1]);
    fl.add_edge(1,3,a[2]);
    fl2.add_edge(1,3,a[2]);
    fl.add_edge(1,4,a[3]);
    fl2.add_edge(1,4,a[3]);
    fl.add_edge(5,10,b[1]);
    fl2.add_edge(5,10,b[1]);
    fl.add_edge(6,10,b[2]);
    fl2.add_edge(6,10,b[2]);
    fl.add_edge(7,10,b[3]);
    fl2.add_edge(7,10,b[3]);
    fl.add_edge(2,6,0x7FFFFFFF);
    fl.add_edge(3,7,0x7FFFFFFF);
    fl.add_edge(4,5,0x7FFFFFFF);
    fl2.add_edge(2,5,0x7FFFFFFF);
    fl2.add_edge(3,6,0x7FFFFFFF);
    fl2.add_edge(4,7,0x7FFFFFFF);
    fl2.add_edge(2,7,0x7FFFFFFF);
    fl2.add_edge(3,5,0x7FFFFFFF);
    fl2.add_edge(4,6,0x7FFFFFFF);
    cout<<tol-fl2.Dinic()<<' '<<fl.Dinic()<<endl;
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