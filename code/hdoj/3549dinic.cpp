#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int from;
    int to;
    int flow;
    int cap;
    Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
};
int G[1010][1010];
int book[10000];
int cur[10000];
int depth[10000];
int n, m, t, s;
int cnt = 0;
vector<Edge> edge;
vector<int> mp[10000];
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
int Dinic(int s, int t)
{
    int ans = 0;
    while (bfs(s, t))
    {
        memset(cur, 0, sizeof(cur));
        ans += dfs(s, 0x7FFFFFFF);
    }
    return ans;
}
void work()
{
    cnt++;
    edge.clear();
    for (int i = 0; i <= n; i++)
    {
        mp[i].clear();
    }
    cin >> n >> m;
    int w, u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> w >> u >> v;
        edge.push_back(Edge(w, u, 0, v));
        edge.push_back(Edge(u, w, 0, 0));
        mp[w].push_back(edge.size() - 2);
        mp[u].push_back(edge.size() - 1);
    }
    t = n;
    s = 1;
    cout << "Case " << cnt << ": " << Dinic(1, n) << endl;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
        work();
    }
    return 0;
}