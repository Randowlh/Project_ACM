class segtree
{
public:
    typedef long long ll;
    struct node
    {
        int v;
        ll l;
        int r;
    } tree[410000];
    ll lazy[410000];
    ll date[110000];
    ll build(int pos, int l, int r)
    {
        if (l == r)
        {
            tree[pos].v = date[l];
            tree[pos].l = l;
            tree[pos].r = r;
            return date[l];
        }
        int mid = (l + r) >> 1;
        int ans = 0;
        ans += build(pos * 2, l, mid);
        ans += build(pos * 2 + 1, mid + 1, r);
        tree[pos].l = l;
        tree[pos].r = r;
        tree[pos].v = ans;
        return ans;
    }
    void update(int l, int r, int v, int pos)
    {
        if (l <= tree[pos].l && tree[pos].r <= r)
        {
            tree[pos].v = (tree[pos].r - tree[pos].l + 1) * v;
            lazy[pos] = v;
            return;
        }
        int m = (tree[pos].l + tree[pos].r) >> 1;
        if (lazy[pos])
        {
            tree[pos * 2].v = lazy[pos] * (m - tree[pos].l + 1);
            tree[pos * 2 + 1].v = lazy[pos] * (tree[pos].r - m);
            lazy[pos * 2] = lazy[pos * 2 + 1] = lazy[pos];
            lazy[pos] = 0;
        }
        if (l <= m)
            update(l, r, v, pos * 2);
        if (r > m)
            update(l, r, v, pos * 2 + 1);
        tree[pos].v = tree[pos * 2].v + tree[pos * 2 + 1].v;
    }
    ll getsum(int l, int r, int pos)
    {
        if (l <= tree[pos].l && tree[pos].r <= r)
            return tree[pos].v;
        int m = (tree[pos].l + tree[pos].r) >> 1;
        if (lazy[pos])
        {
            tree[pos * 2].v = lazy[pos] * (m - tree[pos].l + 1);
            tree[pos * 2 + 1].v = lazy[pos] * (tree[pos].r - m);
            lazy[pos * 2] = lazy[pos * 2 + 1] = lazy[pos];
            lazy[pos] = 0;
        }
        ll sum = 0;
        if (l <= m)
            sum = getsum(l, r, pos * 2);
        if (r > m)
            sum += getsum(l, r, pos * 2 + 1);
        return sum;
    }
} a;