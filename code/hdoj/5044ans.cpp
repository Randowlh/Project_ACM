#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define int long long
const int maxn = 201000;
int mod = 1LL << 63 - 1LL;
int n, m;
vector<int> mp[maxn];
int cnt = 0;
int rk[maxn];
int dfn[maxn], chu[maxn];
int root;
pair<int, int> dege[maxn];
struct segtree
{
    int date[maxn];
    void update(int pos, int a, int b, int w)
    {
        date[a] += w;
        date[b + 1] -= w;
    }
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            date[i] = 0;
        }
    }
} pit, edg;
struct node
{
    int depth, top, sz, fa, hson;
    node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : depth(a), top(b), sz(c), fa(d), hson(e) {}
    inline void init() { depth = 0, top = 0, sz = 0, fa = 0, hson = 0; }
} tree[maxn];
int tree_build(int x, int dep)
{
    tree[x].hson = 0;
    tree[x].depth = dep;
    tree[x].sz = 1;
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] == tree[x].fa)
            continue;
        tree[mp[x][i]].fa = x;
        tree[x].sz += tree_build(mp[x][i], dep + 1);
        if (tree[mp[x][i]].sz > tree[tree[x].hson].sz)
            tree[x].hson = mp[x][i];
    }
    return tree[x].sz;
}
void tree_decomposition(int x, int top)
{
    tree[x].top = top;
    cnt++;
    dfn[x] = cnt;
    rk[cnt] = x;
    if (tree[x].hson == 0)
    {
        chu[x] = cnt;
        return;
    }
    tree_decomposition(tree[x].hson, top);
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] != tree[x].hson && mp[x][i] != tree[x].fa)
        {
            tree_decomposition(mp[x][i], mp[x][i]);
        }
    }
    chu[x] = cnt;
}
inline void tree_path_update(int u, int v, int w)
{
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        pit.update(1, dfn[tree[u].top], dfn[u], w);
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    pit.update(1, dfn[v], dfn[u], w);
}
inline void path_update(int u, int v, int w)
{
    // cout << "u=" << u << "v=" << v << " w=" << w << endl;
    if (u == v)
        return;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        edg.update(1, dfn[tree[u].top], dfn[u], w);
        u = tree[tree[u].top].fa;
        // cout << "u=" << u << "v=" << v << " w=" << w << endl;
    }
    if (u == v)
        return;
    // cout << "u=" << u << "v=" << v << " w=" << w << endl;
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    edg.update(1, dfn[v] + 1, dfn[u], w);
}
inline void work()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i <= n; i++)
        mp[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld%lld", &dege[i].first, &dege[i].second);
        mp[dege[i].first].push_back(dege[i].second);
        mp[dege[i].second].push_back(dege[i].first);
    }
    cnt = 0;
    root = 1;
    tree_build(root, 1);
    tree_decomposition(root, root);
    pit.init(n);
    edg.init(n);
    char opt[100];
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", opt);
        scanf("%lld%lld%lld", &a, &b, &c);
        if (strcmp(opt, "ADD1") == 0)
            tree_path_update(a, b, c);
        else
            path_update(a, b, c);
    }
    int now = 0;
    int aa[maxn];
    for (int i = 1; i <= n; i++)
    {
        now += pit.date[i];
        aa[i] = now;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d", aa[dfn[i]]);
        if (i != n)
            printf(" ");
    }
    printf("\n");
    now = 0;
    for (int i = 1; i <= n; i++)
    {
        now += edg.date[i];
        aa[i] = now;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (i)
            printf(" ");
        if (tree[dege[i].first].depth > tree[dege[i].second].depth)
            printf("%d", aa[dfn[dege[i].first]]);
        else
            printf("%d", aa[dfn[dege[i].second]]);
    }
    printf("\n");
    return;
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    while (scanf("%lld", &t) != EOF)
    {
        for (int i = 1; i <= t; i++)
        {
            printf("Case #%lld:\n", i);
            work();
        }
    }
    return 0;
}