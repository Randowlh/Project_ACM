#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct lca
{
#define maxn 41000
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
        queue<int> q;
        for (int i = 0; i <= n; i++)
        {
            l[i] = -1;
        }
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
void work()
{
    int n, m;
    cin >> n >> m;
    int w, u, v;
    lc.init(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> w >> u >> v;
        lc.add_edge(w, u, v);
    }
    lc.preprocess(n);
    for (int i = 0; i < m; i++)
    {
        cin >> w >> u;
        v = lc.getlca(w, u);
        cout << lc.dis[u] + lc.dis[w] - lc.dis[v] * 2 << endl;
    }
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}