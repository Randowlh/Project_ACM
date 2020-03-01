#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
int n, m;
struct node
{
    int l, r;
    int lx, rx;
    int v;
    int len;
    inline void make(int a, int b) { l = a, r = b, lx = b - a + 1, rx = b - a + 1, v = b - a + 1, len = b - a + 1; }
    inline void zero() { lx = 0, rx = 0, v = 0; }
    inline void fill() { lx = len, rx = len, v = len; }
    inline void made(int l, int r, int tv, int s) { lx = l, rx = r, v = tv, l = s; }
} tree[410000];
inline int maxs(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int lazy[410000];
void build(int pos, int l, int r)
{

    if (l == r)
    {
        tree[pos].make(l, r);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    tree[pos].make(l, r);
    return;
}
inline node mg(node a, node b)
{
    node x;
    if (a.r - a.l + 1 == a.lx)
        x.lx = a.lx + b.lx;
    else
        x.lx = a.lx;
    if (b.r - b.l + 1 == b.rx)
        x.rx = a.rx + b.rx;
    else
        x.rx = b.rx;
    x.v = maxs(a.v, maxs(b.v, a.rx + b.lx));
    return x;
}
inline void push_down(int pos)
{
    lazy[lson(pos)] = lazy[pos];
    lazy[rson(pos)] = lazy[pos];
    if (lazy[pos] == -1)
    {
        tree[lson(pos)].fill();
        tree[rson(pos)].fill();
    }
    else
    {
        tree[lson(pos)].zero();
        tree[rson(pos)].zero();
    }
    lazy[pos] = 0;
    return;
}
void update0(int pos, int l, int r)
{
    if (l <= tree[pos].l && tree[pos].r <= r)
    {
        tree[pos].fill();
        if (tree[pos].r != tree[pos].l)
            lazy[pos] = -1;
        return;
    }
    if (lazy[pos])
        push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (l <= mid)
    {
        update0(lson(pos), l, r);
    }
    if (r > mid)
    {
        update0(rson(pos), l, r);
    }
    node tmp = mg(tree[lson(pos)], tree[rson(pos)]);
    tree[pos].lx = tmp.lx;
    tree[pos].rx = tmp.rx;
    tree[pos].v = tmp.v;
    return;
}
void update1(int pos, int l, int r)
{
    if (l <= tree[pos].l && tree[pos].r <= r)
    {
        tree[pos].zero();
        if (tree[pos].r != tree[pos].l)
            lazy[pos] = 1;
        return;
    }
    if (lazy[pos])
        push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (l <= mid)
    {
        update1(lson(pos), l, r);
    }
    if (r > mid)
    {
        update1(rson(pos), l, r);
    }
    node tmp = mg(tree[lson(pos)], tree[rson(pos)]);
    tree[pos].lx = tmp.lx;
    tree[pos].rx = tmp.rx;
    tree[pos].v = tmp.v;
    return;
}
pair<int, int> query(int pos, int num)
{
    if (tree[pos].lx >= num)
        return make_pair(tree[pos].l, num);
    if (tree[pos].r - tree[pos].l + 1 == tree[pos].lx)
        return make_pair(tree[pos].l, tree[pos].lx);
    if (tree[pos].r == tree[pos].l)
        return make_pair(-1, tree[pos].lx);
    if (lazy[pos])
        push_down(pos);
    pair<int, int> t1 = query(lson(pos), num), t2;
    if (t1.first != -1)
        if (t1.second >= num)
            return t1;
    t2 = query(rson(pos), num);
    if (t2.second < t1.first)
    {
    }
    if (t1.first == -1)
        return t2;
    else
    {
        if (t1.second + t2.second >= num)
            return make_pair(t1.first, num);
        else if (t2.first != -1)
            return make_pair(t1.first, t1.second + t2.second);
        else
            return make_pair(-1, t1.second + t2.second);
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            pair<int, int> t = query(1, b);
            if (t.first == -1 || t.second < b)
                puts("0\n");
            else
            {
                printf("%d\n", t.first);
                update1(1, t.first, t.first + b - 1);
            }
        }
        else
        {
            scanf("%d%d", &b, &c);
            update0(1, b, b + c - 1);
        }
    }
    return 0;
}