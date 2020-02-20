#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
struct node
{
    int l, r, v;
} tree[810000];
int lazy[810000];
inline int ct(int x)
{
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
    return x;
}
inline int make(int n)
{
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans <<= 1;
    }
    return ans;
}
void build(int l, int r, int pos)
{
    lazy[pos] = 0;
    if (l == r)
    {
        tree[pos].v = 1;
        tree[pos].l = l;
        tree[pos].r = r;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, pos * 2);
    build(mid + 1, r, pos * 2 + 1);
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].v = 1;
    return;
}
int update(int l, int r, int v, int pos)
{
    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        tree[pos].v = v;
        if (tree[pos].r != tree[pos].l)
            lazy[pos] = tree[pos].v;
        return tree[pos].v;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    int ans = 0;
    if (lazy[pos] != 0)
    {
        tree[pos * 2].v = lazy[pos];
        tree[pos * 2 + 1].v = lazy[pos];
        lazy[pos * 2] = lazy[pos * 2 + 1] = lazy[pos];
        lazy[pos] = 0;
    }
    if (l <= mid)
    {
        ans = ans | update(l, r, v, pos * 2);
    }
    else
        ans = ans | tree[pos * 2].v;
    if (r > mid)
    {
        ans = ans | update(l, r, v, pos * 2 + 1);
    }
    else
    {
        ans = ans | tree[pos * 2 + 1].v;
    }
    tree[pos].v = ans;
    return ans;
}
int query(int l, int r, int pos)
{

    if (tree[pos].l >= l && tree[pos].r <= r)
    {
        return tree[pos].v;
    }
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    int ans = 0;
    if (lazy[pos])
    {
        tree[pos * 2].v = lazy[pos];
        tree[pos * 2 + 1].v = lazy[pos];
        lazy[pos * 2] = lazy[pos * 2 + 1] = lazy[pos];
        lazy[pos] = 0;
    }
    if (l <= mid)
        ans = ans | query(l, r, pos * 2);
    if (r > mid)
    {
        ans = ans | query(l, r, pos * 2 + 1);
    }
    return ans;
}
int main()
{
    //reopen("in.txt", "r", stdin);
    int l, t, o;
    while (scanf("%d%d%d", &l, &t, &o) == 3)
    {
        build(1, l, 1);
        char s[10];
        int a, b, c;
        for (int i = 0; i < o; i++)
        {
            scanf("%s", s);
            if (s[0] == 'C')
            {
                scanf("%d%d%d", &a, &b, &c);
                if (a > b)
                    swap(a, b);
                update(a, b, make(c), 1);
            }
            else
            {
                scanf("%d%d", &a, &b);
                if (a > b)
                {
                    swap(a, b);
                }
                int tmp = query(a, b, 1);
                printf("%d\n", ct(tmp));
            }
        }
    }
    return 0;
}