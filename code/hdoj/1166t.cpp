#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define bug puts("here");
struct segtree
{
#define rson(a) (a << 1 | 1)
#define lson(b) (b << 1)
    ll sum[100000];
    vector<int> date;
    int size;
    ll lazy[100000];
    void clear()
    {
        date.clear();
        memset(sum, 0, sizeof(sum));
        memset(lazy, 0, sizeof(lazy));
        return;
    }
    void build(vector<int> a)
    {
        date = a;
        bd(1, 0, a.size() - 1);
        size = a.size() - 1;
        for (int i = 1; i <= a.size() * 2; i++)
            lazy[i] = 0;
        return;
    }
    ll bd(int k, int l, int r)
    {
        if (l == r)
        {
            sum[k] = date[l];
            return sum[k];
        }
        int mid = (l + r) / 2;
        int tol = 0;
        tol += bd(lson(k), l, mid);
        tol += bd(rson(k), mid + 1, r);
        sum[k] = tol;
        return tol;
    }
    void putdown(int pos, int nowleft, int nowright)
    {
        int m = (nowleft + nowright) / 2;
        sum[lson(pos)] += lazy[pos] * (m - nowleft + 1), sum[rson(pos)] += lazy[pos] * (nowright - m);
        lazy[lson(pos)] += lazy[pos], lazy[rson(pos)] += lazy[pos];
        lazy[pos] = 0;
    }
    ll query(int left, int right, int nowleft, int nowright, int pos)
    {
        if (left <= nowleft && nowright <= right)
            return sum[pos];
        int m = (nowright + nowleft) >> 1;
        if (lazy[pos])
        {
            putdown(pos, nowleft, nowright);
        }
        int sum = 0;
        if (left <= m)
            sum = query(left, right, nowleft, m, lson(pos));
        if (right > m)
            sum += query(left, right, m + 1, nowright, rson(pos));

        return sum;
    }
    ll getsum(int pos)
    {
        if (pos > size)
            return -1;
        else
            return query(pos, pos, 0, size, 1);
    }
    ll getsum_range(int left, int right)
    {
        return query(left, right, 0, size, 1);
    }
    void update(int pos, int v)
    {
        update_range(pos, pos, v, 0, size, 1);
    }
    void update_rg(int left, int right, int v)
    {
        update_range(left, right, v, 0, size, 1);
    }
    void update_range(int left, int right, int v, int nowleft, int nowright, int pos)
    {
        if (left <= nowleft && nowright <= right)
        {
            sum[pos] += (nowleft - nowright + 1) * v, lazy[pos] += v;
            return;
        }
        int m = (nowleft + nowright) >> 1;
        if (lazy[pos] && nowleft != nowright)
        {
            putdown(pos, nowleft, nowright);
        }
        if (left <= m)
            update_range(left, right, v, nowleft, m, lson(pos));
        if (right > m)
            update_range(left, right, v, m + 1, nowright, rson(pos));
        sum[pos] = sum[lson(pos)] + sum[rson(pos)];
    }
} node;
int main()
{
    //  freopen("in.txt", "r", stdin);
    segtree node;
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        node.clear();
        int n;
        cin >> n;
        vector<int> v;
        int tp;
        for (int i = 0; i < n; i++)
        {
            cin >> tp;
            v.push_back(tp);
        }
        string tmp;
        node.build(v);
        cout << "Case " << q << ":" << endl;
        while (cin >> tmp)
        {
            if (tmp == "End")
                break;
            if (tmp == "Query")
            {
                int a, b;
                cin >> a >> b;
                cout << node.getsum_range(a - 1, b - 1) << endl;
            }
            if (tmp == "Add")
            {
                int a, b;
                cin >> a >> b;
                node.update(a - 1, b);
            }
            if (tmp == "Sub")
            {
                int a, b;
                cin >> a >> b;
                node.update(a - 1, -b);
            }
        }
    }
    return 0;
}
// 1
// 10
// 1 2 3 4 5 6 7 8 9 10
// Query 1 3
// Add 3 6
// Query 2 7
// Sub 10 2
// Add 6 3
// Query 3 10
// End