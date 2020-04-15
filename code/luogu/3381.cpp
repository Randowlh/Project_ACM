#include <bits/stdc++.h>
using namespace std;
struct LCF
{
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cost;
        Edge(int fr, int t, int f, int cc) : from(fr), to(t), flow(f), cost(cc) {}
    };
#define inf 0x3f3f3f3f
#define maxn 200010
    int book[maxn];
    int dis[maxn];
    int n, m, s, t, ans = 0;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void add_edge(int x, int y, int flow, int cost)
    {
        edge.push_back(Edge(x, y, flow, cost));
        edge.push_back(Edge(y, x, 0, -cost));
        mp[x].push_back(edge.size() - 2);
        mp[y].push_back(edge.size() - 1);
    }
    inline bool spfa()
    {
        for (int i = 0; i <= n; i++)
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
        {
            return flow;
        }
        int used = 0, a;
        for (int i = 0; i < mp[x].size(); i++)
        {
            int to = edge[mp[x][i]].to;
            if (!book[to] && edge[mp[x][i]].flow && dis[x] - edge[mp[x][i]].cost == dis[to])
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
    inline int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            memset(book, 0, sizeof(book));
            flow += dfs(s, inf);
        }
        return flow;
    }
} tmp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    cin >> tmp.n >> tmp.m >> tmp.s >> tmp.t;
    int w, u, v, c;
    tmp.edge.clear();
    for (int i = 0; i <= tmp.n; i++)
    {
        tmp.mp[i].clear();
    }
    for (int i = 0; i < tmp.m; i++)
    {
        cin >> w >> u >> v >> c;
        tmp.add_edge(w, u, v, c);
    }
    cout << tmp.cost_flow() << ' ' << tmp.ans << endl;
    return 0;
}