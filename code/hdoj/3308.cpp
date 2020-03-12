#include <bits/stdc++.h>
using namespace std;
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
struct node
{
    int l, r;
    int ls, rs;
    int v;
    int len;
} tree[810000];
vector<int> date;
inline void push_up(int pos)
{
    tree[pos].l = tree[lson(pos)].l;
    tree[pos].r = tree[rson(pos)].r;
    tree[pos].len = tree[pos].r - tree[pos].l + 1;
    tree[pos].ls = tree[lson(pos)].ls;
    tree[pos].rs = tree[rson(pos)].rs;
    tree[pos].v = max(tree[lson(pos)].v, tree[rson(pos)].v);
    if (date[tree[lson(pos)].r] < date[tree[rson(pos)].l])
    {
        if (tree[lson(pos)].ls == tree[lson(pos)].len)
            tree[pos].ls += tree[rson(pos)].ls;
        if (tree[rson(pos)].rs == tree[rson(pos)].len)
            tree[pos].rs += tree[lson(pos)].rs;
        tree[pos].v = max(tree[pos].v, tree[lson(pos)].rs + tree[rson(pos)].ls);
    }
    return;
}
inline node merge(node a, node b)
{
    node x;
    x.l = a.l;
    x.r = b.r;
    x.len = x.r - x.r + 1;
    x.ls = a.ls;
    x.rs = b.rs;
    x.v = max(a.v, b.v);
    if (date[a.r] < date[b.l])
    {
        if (a.ls == a.len)
            x.ls += b.ls;
        if (b.ls == b.len)
            x.rs += a.rs;
        x.v = max(x.v, a.rs + b.ls);
    }
    return x;
}
void build(int pos, int l, int r)
{
    if (l == r)
    {
        tree[pos].ls = 1;
        tree[pos].rs = 1;
        tree[pos].v = 1;
        tree[pos].l = l;
        tree[pos].r = r;
        tree[pos].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    push_up(pos);
    return;
}
void update(int pos, int a, int t)
{
    if (tree[pos].l == tree[pos].r)
    {
        date[tree[pos].l] = a;
        return;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (t <= mid)
        update(lson(pos), a, t);
    else
        update(rson(pos), a, t);
    push_up(pos);
    return;
}
node query(int pos, int l, int r)
{
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        return tree[pos];
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (mid >= l && r > mid)
    {
        node a = query(lson(pos), l, r);
        node b = query(rson(pos), l, r);
        return merge(a, b);
    }
    if (mid >= l)
        return query(lson(pos), l, r);
    if (r > mid)
        return query(rson(pos), l, r);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    int n, m;
    for (int q = 0; q < t; q++)
    {
        cin >> n >> m;
        date.clear();
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            date.push_back(tmp);
        }
        build(1, 0, n - 1);
        char C;
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> C >> a >> b;
            if (C == 'Q')
            {
                cout << query(1, a, b).v << endl;
            }
            else
                update(1, b, a);
        }
    }
}