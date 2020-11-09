ll tree[500000];
int n;
int cnt = 0;
int lowbit(int x)
{
    return x & -x;
}
int update(int x, int v)
{
    while (x <= n){tree[x] += v;x += lowbit(x);}
}
ll query(int x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
ll get_range(int l, int r)
{
    return query(r) - query(l - 1);
}