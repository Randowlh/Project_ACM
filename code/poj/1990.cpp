void update_range(int pos, int l, int r, int v)
{
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        if (tree[pos].l == tree[pos].r)
            tree[pos].v += v;
        else
            lazy[pos] += v;
        return;
    }
    if (lazy[pos])
    {
        tree[pos].v += (tree[pos].r - tree[pos].l + 1) * lazy[pos];
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos] = 0;
    }
    tree[pos].v += (min(r, tree[pos].r) - max(l, tree[pos].l) + 1) * v;
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (mid >= l)
    {
        update_range(pos * 2, l, r, v);
    }
    if (mid < r)
    {
        update_range(pos * 2 + 1, l, r, v);
    }
    return;
}
int query(int pos, int l, int r)
{
    if (l <= tree[pos].l && tree[pos].r <= r)
    {
        int ans = 0;
        if (lazy[pos])
        {
            ans += (tree[pos].r - tree[pos].l + 1) * lazy[pos];
        }
        ans += tree[pos].v;
        return ans;
    }
    if (lazy[pos])
    {
        tree[pos].v += (tree[pos].r - tree[pos].l + 1) * lazy[pos];
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos] = 0;
    }
    int ans = 0;
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (l <= mid)
    {
        ans += query(pos * 2, l, r);
    }
    if (r > mid)
    {
        ans += query(pos * 2 + 1, l, r);
    }
    return ans;
}