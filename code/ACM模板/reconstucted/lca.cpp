struct lca
{
#define maxn 11000
#define logmaxn ((int)log(maxn) / (int)log(2));
    vector<pair<int, int>> mp[maxn];
    int root = 1;
    int fa[maxn];
    int p[maxn][43];
    int l[maxn];
    int dis[maxn];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
            mp[i].clear();
    }
    void add_edge(int w, int u, int v = 1)
    {
        pair<int, int> x(w, v);
        mp[u].push_back(x);
        x.first = u;
        mp[w].push_back(x);
    }
    void preprocess(int n, int b = 1)
    {
        set<int> s;
        for (int i = 0; i <= n; i++)
            l[i] = -1;
        for (int i = 1; i <= n; i++)
        {
            if (s.count(find(i)) == 0)
            {
                s.insert(find(i));
                root = find(i);
                queue<int> q;
                fa[root] = -1;
                l[root] = 0;
                dis[root] = 0;
                q.push(root);
                while (!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    for (int i = 0; i < mp[now].size(); i++)
                    {
                        pair<int, int> &t = mp[now][i];
                        if (l[t.first] == -1)
                        {
                            l[t.first] = l[now] + 1;
                            dis[t.first] = dis[now] + t.second;
                            fa[t.first] = now;
                            q.push(t.first);
                        }
                    }
                }
            }
        }
        for (int i = b; i < n + b; i++)
            for (int j = 0; 1 << j < n + b; j++)
                p[i][j] = -1;
        for (int i = b; i < n + b; i++)
            p[i][0] = fa[i];
        for (int j = 1; 1 << j < n + b; j++)
            for (int i = b; i < n + b; i++)
                if (p[i][j - 1] != -1)
                    p[i][j] = p[p[i][j - 1]][j - 1];
    }
    int getlca(int u, int v)
    {
        int log;
        if (l[u] < l[v])
            swap(u, v);
        for (log = 1; 1 << log <= l[u]; log++)
            ;
        log--;
        for (int i = log; i >= 0; i--)
            if (l[u] - (1 << i) >= l[v])
                u = p[u][i];
        if (u == v)
            return u;
        for (int i = log; i >= 0; i--)
            if (p[u][i] != -1 && p[u][i] != p[v][i])
                u = p[u][i], v = p[v][i];
        return fa[u];
    }
} lc;