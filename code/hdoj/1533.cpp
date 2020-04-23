#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define int long long
struct LCF
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
#define maxn 201110
    int book[maxn];
    int dis[maxn];
    int n, m, s, t, ans;
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
        for (int i = 0; i <= n * m + 100; i++)
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
    void init(int tn, int tm, int ts, int tt)
    {
        for (int i = 0; i <= tn * tm + 100; i++)
            mp[i].clear();
        edge.clear();
        n = tn;
        m = tm;
        s = ts;
        t = tt;
        ans = 0;
    }
    int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            for (int i = 0; i <= n * m + 200; i++)
                book[i] = 0;
            flow += dfs(s, inf);
        }
        return flow;
    }
} tmp;
char mp[1100][1100];
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int n = 0, m = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        //memset(mp, 0, sizeof(mp));
        tmp.init(n, m, 0, n * m + 7);
        vector<int> hs, ps;
        vector<pair<int, int>> lh, lp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == 'm')
                {
                    ps.push_back(i * m + j + 1);
                    lh.push_back(make_pair(i, j));
                }
                else if (mp[i][j] == 'H')
                {
                    hs.push_back(i * m + j + 1);
                    lp.push_back(make_pair(i, j));
                }
            }
        for (int i = 0; i < ps.size(); i++)
            tmp.add_edge(0, ps[i], 1, 0);
        for (int i = 0; i < ps.size(); i++)
            for (int j = 0; j < hs.size(); j++)
                tmp.add_edge(ps[i], hs[j], 0x3f3f3f3f - 1, abs(lh[i].first - lp[j].first) + abs(lh[i].second - lp[j].second));
        for (int i = 0; i < hs.size(); i++)
            tmp.add_edge(hs[i], n * m + 7, 1, 0);
        tmp.cost_flow();
        cout << tmp.ans << endl;
    }
    return 0;
}