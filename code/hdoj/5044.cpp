#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 101000;
int n, m;
vector<int> mp[maxn];
int cnt;
int rk[maxn];
int dfn[maxn], chu[maxn];
int date[maxn];
inline int lowbit(int x) { return x & -x; }

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
        return;
    tree_decomposition(tree[x].hson, top);
    for (int i = 0; i < mp[i].size(); i++)
    {
        if (mp[x][i] != tree[x].hson && mp[x][i] != tree[x].fa)
            tree_decomposition(mp[x][i], mp[x][i]);
    }
    chu[x] = cnt;
}
void work()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i <= n; i++)
    {
        tree[i].init();
        mp[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    tree[1].fa = -1;
    tree_build(1, 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}