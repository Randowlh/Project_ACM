#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define int long long
const int maxn = 101000;
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
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
    struct seg
    {
        int v;
        int l;
        int r;
        int lazy;
        inline void set(int a = 0, int b = 0, int c = 0, int d = 0) { v = a, l = b, r = c, lazy = d; }
    } date[4 * maxn + 100];
    inline void pushup(int pos)
    {
        date[pos].v = date[lson(pos)].v;
        date[pos].v += date[rson(pos)].v;
    }
    inline void pushdown(int pos)
    {
        if (!date[pos].lazy)
            return;
        date[lson(pos)].lazy += date[pos].lazy;
        date[lson(pos)].lazy %= mod;
        date[rson(pos)].lazy += date[pos].lazy;
        date[rson(pos)].lazy %= mod;
        date[rson(pos)].v += date[pos].lazy * (date[rson(pos)].r - date[rson(pos)].l + 1) % mod;
        date[rson(pos)].v %= mod;
        date[lson(pos)].v += date[pos].lazy * (date[lson(pos)].r - date[lson(pos)].l + 1) % mod;
        date[rson(pos)].v %= mod;
        date[pos].lazy = 0;
    }
    void build(int pos, int l, int r)
    {
        if (l == r)
        {
            date[pos].set(0, l, r);
            return;
        }
        date[pos].set(0, l, r);
        int mid = (l + r) >> 1;
        build(lson(pos), l, mid);
        build(rson(pos), mid + 1, r);
        pushup(pos);
    }
    void update(int pos, int l, int r, int v)
    {
        if (date[pos].l >= l && date[pos].r <= r)
        {
            date[pos].lazy += v;
            date[pos].lazy %= mod;
            date[pos].v += (date[pos].r - date[pos].l + 1) * v % mod;
            date[pos].v %= mod;
            return;
        }
        int mid = (date[pos].l + date[pos].r) >> 1;
        pushdown(pos);
        if (l <= mid)
            update(lson(pos), l, r, v);
        if (r >= mid + 1)
            update(rson(pos), l, r, v);
        pushup(pos);
    }
    int query(int pos, int l, int r)
    {
        if (date[pos].l >= l && date[pos].r <= r)
            return date[pos].v;
        pushdown(pos);
        int ans = 0;
        int mid = (date[pos].l + date[pos].r) >> 1;
        if (l <= mid)
            ans += query(lson(pos), l, r);
        if (r >= mid + 1)
            ans += query(rson(pos), l, r);
        ans %= mod;
        return ans;
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
inline int tree_path_sum(int u, int v)
{
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        tol += pit.query(1, dfn[tree[u].top], dfn[u]);
        tol %= mod;
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    tol += pit.query(1, dfn[v], dfn[u]);
    tol %= mod;
    return tol;
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
inline int path_sum(int u, int v)
{
    if (u == v)
        return 0;
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        tol += edg.query(1, dfn[tree[u].top], dfn[u]);
        tol %= mod;
        u = tree[tree[u].top].fa;
    }
    if (u == v)
        return tol;
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    tol += edg.query(1, dfn[v] + 1, dfn[u]);
    tol %= mod;
    return tol;
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
    pit.build(1, 1, n);
    edg.build(1, 1, n);
    string opt;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> opt;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (opt == "ADD1")
            tree_path_update(a, b, c);
        else
            path_update(a, b, c);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", pit.query(1, dfn[i], dfn[i]));
    printf("\n");
    for (int i = 0; i < n - 1; i++)
        if (tree[dege[i].first].depth >= tree[dege[i].second].depth)
            printf("%d ", edg.query(1, dfn[dege[i].first], dfn[dege[i].first]));
        else
            printf("%d ", edg.query(1, dfn[dege[i].second], dfn[dege[i].second]));
    printf("\n");
    return;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++)
    {
        printf("Case #%lld:\n", i);
        work();
    }
    return 0;
}