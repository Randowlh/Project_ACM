#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 610;
int n, m;
struct blossemtree
{
    vector<int> g[maxn];
    queue<int> q;
    int fa[maxn];
    int type[maxn], link[maxn], Next[maxn], vis[maxn];
    int find(int x)
    {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }
    void add(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void combine(int x, int lca)
    {
        while (x != lca)
        {
            int u = link[x], v = Next[u];
            if (find(v) != lca)
                Next[v] = u;
            if (type[u] == 1)
                type[u] = 2, q.push(u);
            fa[find(x)] = find(u);
            fa[find(u)] = find(v); //注意这里不能直接写成lca
            x = v;
        }
    }
    void contrack(int x, int y)
    {
        int lca = x;
        memset(vis, 0, sizeof(vis));
        for (int i = x; i; i = Next[link[i]])
        {
            i = find(i);
            vis[i] = 1;
        }
        for (int i = y; i; i = Next[link[i]])
        {
            i = find(i);
            if (vis[i])
            {
                lca = i;
                break;
            }
        }
        if (lca != find(x))
            Next[x] = y;
        if (lca != find(y))
            Next[y] = x;
        combine(x, lca);
        combine(y, lca);
    }
    void bfs(int S)
    {
        memset(type, 0, sizeof(type));
        memset(Next, 0, sizeof(Next));
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        while (!q.empty())
            q.pop();
        q.push(S);
        type[S] = 2; //这里之前写成 type[S]=1了，抱歉！
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < g[x].size(); i++)
            {
                int y = g[x][i];
                if (find(x) == find(y) || link[x] == y || type[y] == 1)
                    continue;
                if (type[y] == 2)
                    contrack(x, y);
                else if (link[y])
                {
                    Next[y] = x;
                    type[y] = 1;
                    type[link[y]] = 2;
                    q.push(link[y]);
                }
                else
                {
                    Next[y] = x;
                    int pos = y, u = Next[pos], v = link[u];
                    while (pos)
                    {
                        link[pos] = u;
                        link[u] = pos;
                        pos = v;
                        u = Next[pos];
                        v = link[u];
                    }
                    return;
                }
            }
        }
    }
    int maxmatch()
    {
        for (int i = 1; i <= n; i++)
            if (!link[i])
                bfs(i);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (link[i])
                ans++;
        return ans / 2;
    }
    void init()
    {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        memset(link, 0, sizeof(link));
    }
} tree;
int main()
{

    while (~scanf("%d%d", &n, &m))
    {
        tree.init();
        int N = n;
        int aa;
        for (int i = 1; i <= n; ++i)
        {
            cin >> aa;
            if (aa == 2)
            {
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            tree.add(u, v);
        }
        printf("%d\n", tree.maxmatch());
    }
    return 0;
}
