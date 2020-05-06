#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define INF 10000000000000000
class DC
{
public:
#define maxn 2600
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    int book[maxn];
    int cur[maxn];
    int depth[maxn];
    int n, m, t, s;
    int cnt = 0;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void clear(int n = 2574)
    {
        for (int i = 0; i < n; i++)
            mp[i].clear();
        edge.clear();
    }
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
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
} fl;
inline int getnum(int i, int j)
{
    return (i - 1) * 25 + j;
}
int cnt = 1;
void work()
{
    cout << "Case #" << cnt << ": ";
    cnt++;
    int n;
    cin >> n;
    fl.clear();
    fl.s = 0;
    fl.t = 2523;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (b - a > 0)
            {
                fl.add_edge(0, getnum(i, j), b - a);
                sum += b - a;
            }
            else
                fl.add_edge(getnum(i, j), 2523, a - b);
            int ti, tj;
            for (int q = 0; q < c; q++)
            {
                cin >> ti >> tj;
                int tt = getnum(ti, tj);
                fl.add_edge(getnum(i, j), tt, INF);
            }
        }
    }
    cout << sum - fl.Dinic() << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}