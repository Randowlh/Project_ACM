#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, ans, dep[105], que[105];
struct edge
{
    int w, to, rev;
};
vector<edge> e[105];
bool bfs()
{
    int i, x, sz, head = 0, tail = 1;
    memset(dep, 0, sizeof(dep));
    dep[0] = 1;
    que[1] = 0;
    while (head ^ tail)
    {
        x = que[++head];
        for (i = 0, sz = e[x].size(); i < sz; i++)
            if (!dep[e[x][i].to] && e[x][i].w)
                dep[e[x][i].to] = dep[x] + 1, que[++tail] = e[x][i].to;
    }
    return dep[2 * n + 1];
}
int dfs(int x, int s)
{
    int i, z, sz, res = 0;
    if (x == 2 * n + 1 || !s)
        return s;
    for (i = 0, sz = e[x].size(); i < sz; i++)
        if (dep[e[x][i].to] > dep[x] && e[x][i].w)
        {
            z = dfs(e[x][i].to, min(s, e[x][i].w));
            e[x][i].w -= z;
            e[e[x][i].to][e[x][i].rev].w += z;
            s -= z;
            res += z;
            if (!s)
                return res;
        }
    dep[x] = 0;
    return res;
}
void dinic()
{
    while (bfs())
        ans -= dfs(0, INF);
}
int main()
{
    int i, x, y;
    while (~scanf("%d%d", &n, &m))
    {
        for (i = 0; i <= 2 * n + 1; i++)
            e[i].clear();
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            ans += x;
            e[0].push_back((edge){x, i, e[i].size()});
            e[i].push_back((edge){0, 0, e[0].size() - 1});
            e[n + i].push_back((edge){x, 2 * n + 1, e[2 * n + 1].size()});
            e[2 * n + 1].push_back((edge){0, n + i, e[n + i].size() - 1});
        }
        while (m--)
        {
            scanf("%d%d", &x, &y);
            e[x].push_back((edge){1, n + y, e[n + y].size()});
            e[n + y].push_back((edge){0, x, e[x].size() - 1});
            e[y].push_back((edge){1, n + x, e[n + x].size()});
            e[n + x].push_back((edge){0, y, e[y].size() - 1});
        }
        dinic();
        printf("%s\n", !ans ? "Yes" : "No");
    }
    return 0;
}