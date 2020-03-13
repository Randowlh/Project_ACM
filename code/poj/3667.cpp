#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
typedef long long ll;
struct node
{
    int l, r;
    int ls, rs;
    int v;
    int lazy;
    inline int len()
    {
        return r - l + 1;
    }
    inline void init(int t)
    {
        l = t, r = t, rs = 1, ls = 1, v = 1, lazy = 0;
        return;
    }
} tree[50101 << 2];
inline void push_up(int pos)
{
    tree[pos].lazy = 0;
    tree[pos].l = tree[lson(pos)].l;
    tree[pos].r = tree[rson(pos)].r;
    tree[pos].ls = tree[lson(pos)].ls;
    tree[pos].rs = tree[rson(pos)].rs;
    if (tree[lson(pos)].ls == tree[lson(pos)].len())
        tree[pos].ls += tree[rson(pos)].ls;
    if (tree[rson(pos)].rs == tree[rson(pos)].len())
        tree[pos].rs += tree[lson(pos)].rs;
    tree[pos].v = max(tree[rson(pos)].v, max(tree[lson(pos)].v, tree[rson(pos)].ls + tree[lson(pos)].rs));
    return;
}
inline void push_down(int pos)
{
    tree[lson(pos)].lazy = tree[pos].lazy;
    tree[rson(pos)].lazy = tree[pos].lazy;
    if (tree[pos].lazy == -1)
    {
        tree[rson(pos)].ls = tree[rson(pos)].len();
        tree[rson(pos)].rs = tree[rson(pos)].len();
        tree[rson(pos)].v = tree[rson(pos)].len();
        tree[lson(pos)].ls = tree[lson(pos)].len();
        tree[lson(pos)].rs = tree[lson(pos)].len();
        tree[lson(pos)].v = tree[lson(pos)].len();
    }
    else
    {
        tree[rson(pos)].ls = 0;
        tree[rson(pos)].rs = 0;
        tree[rson(pos)].v = 0;
        tree[lson(pos)].ls = 0;
        tree[lson(pos)].rs = 0;
        tree[lson(pos)].v = 0;
    }
    tree[pos].lazy = 0;
    return;
}
void update(int pos, int l, int r, int flag)
{
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        if (tree[pos].l != tree[pos].r)
            tree[pos].lazy = flag;
        if (flag == -1)
        {
            tree[pos].ls = tree[pos].len();
            tree[pos].rs = tree[pos].len();
            tree[pos].v = tree[pos].len();
        }
        else
        {
            tree[pos].ls = 0;
            tree[pos].rs = 0;
            tree[pos].v = 0;
        }
        return;
    }
    if (tree[pos].lazy)
        push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (l <= mid)
        update(lson(pos), l, r, flag);
    if (r > mid)
        update(rson(pos), l, r, flag);
    push_up(pos);
}
void build(int pos, int l, int r)
{
    if (l == r)
    {
        tree[pos].init(l);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    push_up(pos);
    return;
}
int query(int pos, int num)
{
    if (tree[pos].ls >= num)
    {
        return tree[pos].l;
    }
    if (tree[pos].lazy)
    {
        push_down(pos);
    }
    if (tree[pos].v >= num)
    {
        if (tree[lson(pos)].v >= num)
            return query(lson(pos), num);
        if (tree[lson(pos)].rs + tree[rson(pos)].ls >= num)
            return tree[lson(pos)].r - tree[lson(pos)].rs + 1;
        if (tree[rson(pos)].v >= num)
            return query(rson(pos), num);
    }
    return 0;
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        build(1, 1, n);
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            if (a == 1)
            {
                scanf("%d", &b);
                int t = query(1, b);
                printf("%d\n", t);
                if (t != 0)
                    update(1, t, t + b - 1, 1);
            }
            else
            {
                scanf("%d%d", &b, &c);
                update(1, b, min(n, b + c - 1), -1);
            }
        }
    }
}