#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segtree
{
#define rson(a) (a << 1 | 1)
#define lson(b) (b << 1)
    // int date[100000];
    ll sum[100000];
    vector<int> date;
    int size;
    ll lazy[100000];
    void build(vector<int> a)
    {
        date = a;
        bd(1, 0, a.size());
        for (int i = 1; i <= a.size() * 2; i++)
            lazy[i] = 0;
        return;
    }
    int bd(int k /*当前节点的编号*/, int l /*当前区间的左边界*/, int r /*当前区间的右边界*/)
    {
        if (l == r) //递归到叶节点
        {
            sum[k] = date[l]; //其中number数组为给定的初值
            return sum[k];
        }
        int mid = (l + r) / 2; //计算左右子节点的边界
        int tol = 0;
        tol += bd(k * 2, l, mid);         //递归到左儿子
        tol += bd(k * 2 + 1, mid + 1, r); //递归到右儿子
        sum[k] = tol;
        return tol; //记得要用左右子区间的值更新该区间的值
    }
    void putdown(int pos, int nowleft, int nowright)
    {
        int m = (nowleft + nowright) / 2;
        // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        sum[lson(pos)] += lazy[pos] * (m - nowleft + 1), sum[rson(pos)] += lazy[pos] * (nowright - m),
            lazy[lson(pos)] += lazy[pos], lazy[rson(pos)] += lazy[pos]; // 将标记下传给子节点
        lazy[pos] = 0;                                                  // 清空当前节点的标记
    }
    void update(int pos, int v)
    {
        pos--;
        pos += size;
        sum[pos] = v;
        while (pos > 1)
        {
            pos /= 2;
            sum[pos] = sum[lson(pos)] + sum[rson(pos)];
        }
        return;
    }
    int query(int left, int right, int nowleft, int nowright, int pos)
    {
        // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
        // 为当前节点的编号
        if (left <= nowleft && nowright <= right)
            return sum[pos];
        // 当前区间为询问区间的子集时直接返回当前区间的和
        int m = (right + left) >> 1;
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
    int getsum(int pos)
    {
        return query(pos, pos, 0, size - 1, 1);
    }
    int getsum_range(int left, int right)
    {
        return query(left, right, 1, size, 1);
    }
    void update_range(int left, int right, int v, int nowleft, int nowright, int pos)
    {
        // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
        // 为当前节点的编号
        if (left <= nowleft && nowright <= right)
        {
            sum[pos] += (nowleft - nowright + 1) * v, lazy[pos] += v;
            return;
        } // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
        int m = (nowleft + nowright) / 2;
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
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    //segtree node;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    node.build(v);
    for (int i = 0; i < 20; i++)
    {
        cout << node.sum[i] << endl;
    }
    cout << endl;
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        node.update(a, b);
    }
    for (int i = 0; i < 20; i++)
    {
        cout << node.getsum(i + 1) << endl;
    }
    cout << endl;
    cin >> m;
    int c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        node.update_range(a, b, c, 0, node.size, 1);
    }
    for (int i = 0; i < 20; i++)
    {
        cout << node.getsum(i) << endl;
    }
}
