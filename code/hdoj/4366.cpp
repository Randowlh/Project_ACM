#include <bits/stdc++.h>
using namespace std;
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
vector<int> mp[110000];
int dfn[110000];
int ddfn[110000];
int ed[110000];
struct em
{
    int up, lo, nl, num;
    bool operator<(em a)
    {
        if (nl == a.nl)
            return dfn[num] < dfn[a.num];
        return nl > a.nl;
    }
};
struct node
{
    int l, r;
    int v, num;
} tree[110000 << 2];

inline void push_up(int pos)
{
    if (tree[lson(pos)].v > tree[rson(pos)].v)
    {
        tree[pos].v = tree[lson(pos)].v;
        tree[pos].num = tree[lson(pos)].num;
    }
    else
    {
        tree[pos].v = tree[rson(pos)].v;
        tree[pos].num = tree[rson(pos)].num;
    }
    return;
}
void build(int pos, int l, int r)
{
    tree[pos].v = -1;
    tree[pos].l = l;
    tree[pos].r = r;
    if (l == r)
    {
        tree[pos].num = l;
        return;
    }
    tree[pos].num = -1;
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    return;
}
void update(int pos, int x, int v)
{
    if (tree[pos].r == tree[pos].l)
    {
        tree[pos].v = v;
        return;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (mid >= x)
        update(lson(pos), x, v);
    else
        update(rson(pos), x, v);
    push_up(pos);
    return;
}
pair<int, int> query(int pos, int l, int r)
{
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        return make_pair(tree[pos].v, tree[pos].num);
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    pair<int, int> ma, tt;
    ma.first = -1;
    ma.second = -1;
    if (l <= mid)
        ma = query(lson(pos), l, r);
    if (r > mid)
    {
        tt = query(rson(pos), l, r);
        if (ma.first < tt.first)
            ma = tt;
    }
    return ma;
}
int tim = -1;
void dfs(int x)
{
    tim++;
    dfn[x] = tim;
    ddfn[tim] = x;
    for (int i = 0; i < mp[x].size(); i++)
    {
        dfs(mp[x][i]);
    }
    ed[x] = tim;
}
int ans[110000];
void work()
{
    tim = -1;
    int n, m;
    cin >> n >> m;
    vector<em> v;
    em x;
    build(1, 0, n);
    for (int i = 0; i <= 50050; i++)
    {
        mp[i].clear();
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x.up >> x.lo >> x.nl;
        x.num = i;
        v.push_back(x);
        mp[x.up].push_back(i);
    }
    memset(ans, -1, sizeof(ans));
    dfs(0);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> x = query(1, dfn[v[i].num], ed[v[i].num]);
        if (x.first != -1)
            ans[v[i].num] = ddfn[x.second];
        else
            ans[v[i].num] = -1;
        update(1, dfn[v[i].num], v[i].lo);
    }
    pair<int, int> xa = query(1, dfn[0], ed[0]);
    if (xa.first != -1)
        ans[0] = ddfn[xa.second];
    else
        ans[0] = -1;
    for (int i = 0; i < m; i++)
    {
        int tt;
        cin >> tt;
        cout << ans[tt] << endl;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}