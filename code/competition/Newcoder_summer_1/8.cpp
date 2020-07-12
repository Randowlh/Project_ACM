#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
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
    int book[1010];
    int cur[1010];
    int depth[1010];
    int n, m, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[1010];
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
            memset(cur, 0, sizeof(cur));
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void clear()
    {
        edge.clear();
        for (int i = 0; i < 1000; i++)
        {
            mp[i].clear();
        }
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
} fl;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int n, m;
vector<int> dr;
void work()
{
    while (cin >> n >> m)
    {

        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            dr.push_back(tmp);
        }
        int a, b;
        for (int i = 0; i < m; i++)
        {
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}