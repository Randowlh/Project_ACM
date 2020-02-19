#include <bits/stdc++.h>
using namespace std;
class tree_arr
{
private:
    int n;
    int lowbit(int x)
    {
        return x & -x;
    }
    vector<int> date;
    vector<int> tree;
    void add(int x, int v)
    {
        while (x <= n)
        {
            tree[x] += v;
            x += lowbit(x);
        }
        return;
    }

public:
    void build(vector<int> a)
    {
        n = a.size();
        date.push_back(0);
        int pr = 0;
        for (int i = 0; i < a.size(); i++)
        {
            date.push_back(a[i] - pr);
            pr = a[i];
        }
        tree.resize(date.size());
        for (int i = 1; i <= a.size(); i++)
        {
            add(i, date[i]);
        }
    }
    void add_range(int l, int r, int v)
    {
        add(l, v);
        add(r + 1, -v);
        return;
    }
    long long quer(int x)
    {
        long long ans = 0;
        while (x > 0)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
} node;
int main()
{
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    node.build(v);
    int a, b, c, d;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            node.add_range(b, c, d);
        }
        else
        {
            cin >> b;
            cout << node.quer(b) << endl;
        }
    }
    return 0;
}