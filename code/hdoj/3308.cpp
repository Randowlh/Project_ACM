#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int lv, rv;
    int lo, ro;
    int len;
    int l, r;
} tree[101000];
node mg(int pos1, int pos2)
{
    if (tree[pos1].ro + 1 != tree[pos2].lo)
    {
        if (tree[pos1].len < tree[pos2].len)
            return tree[pos2];
        else
            return tree[pos1];
    }
    else
    {
        if (tree[pos1].rv <= tree[pos2].len)
        {
            node a;
            a.lv = tree[pos1].lv;
            a.lo = tree[pos1].lo;
            a.ro = tree[pos2].ro;
            a.rv = tree[pos2].rv;
            a.len = a.ro - a.lo + 1;
        }
        else if (tree[pos1].len < tree[pos2].len)
            return tree[pos2];
        else
            return tree[pos1];
    }
}
int build(int pos, int l, int r)
{
    if ()
}
int update(int pos, int r, int v)
{
}
node query(int pos, int l, int r)
{
}
int main()
{
}