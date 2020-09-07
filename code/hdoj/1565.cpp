#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
struct Edge
{
    int from;
    int to;
    int flow;
    int cap;
    Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
};
int G[1010][1010];
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
void addedge(int from, int to, int cap)
{
    edge.push_back(Edge(from, to, 0, cap));
    edge.push_back(Edge(to, from, 0, 0));
    mp[from].push_back(edge.size() - 2);
    mp[to].push_back(edge.size() - 1);
}
void work()
{
    while (cin >> n)
    {
        int sum = 0;
        edge.clear();
        for (int i = 0; i <= n * n + 5; i++)
        {
            mp[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int now = (i - 1) * n + j;
                cin >> G[i][j];
                sum += G[i][j];
                if ((i + j) % 2 == 0)
                {
                    addedge(0, now, G[i][j]);
                    if (i > 1)
                        addedge(now, now - n, inf);
                    if (i < n)
                        addedge(now, now + n, inf);
                    if (j > 1)
                        addedge(now, now - 1, inf);
                    if (j < n)
                        addedge(now, now + 1, inf);
                }
                else
                {
                    addedge(now, n * n + 1, G[i][j]);
                }
            }
        }
        s = 0;
        t = n * n + 1;
        cout << sum - Dinic(0, n * n + 1) << endl;
    }
    return;
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    while (tt--)
    {
        work();
    }
    return 0;
}