#include <bits/stdc++.h>
using namespace std;
struct node
{
    int v;
    int l;
    int r;
};
node tree[801000];
int date[201000];
int n, m;
int build(int pos, int l, int r)
{
    if (l == r)
    {
        tree[pos].l = l;
        tree[pos].r = r;
        tree[pos].v = date[l];
        return date[l];
    }
    int mid = (l + r) >> 1;
    build(pos * 2, l, mid);
    build(pos * 2 + 1, mid + 1, r);
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].v = max(tree[pos * 2].v, tree[pos * 2 + 1].v);
    return tree[pos].v;
}
int update(int x, int v, int pos)
{
    if (tree[pos].l == tree[pos].r)
    {
        tree[pos].v = v;
        return v;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (x <= mid)
        tree[pos].v = max(tree[pos * 2 + 1].v, update(x, v, pos * 2));
    else
        tree[pos].v = max(tree[pos * 2].v, update(x, v, pos * 2 + 1));
    return tree[pos].v;
}
int query(int l, int r, int pos)
{
    int ans = -1;
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        return tree[pos].v;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (l <= mid)
    {
        ans = query(l, r, pos * 2);
    }
    if (r > mid)
    {
        ans = max(ans, query(l, r, pos * 2 + 1));
    }
    return ans;
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &date[i]);
        }
        build(1, 1, n);
        char tmp[100];
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%s %d%d", &tmp, &a, &b);
            if (tmp[0] == 'Q')
            {
                printf("%d\n", query(a, b, 1));
            }
            else
            {
                update(a, b, 1);
            }
        }
    }
    return 0;
}