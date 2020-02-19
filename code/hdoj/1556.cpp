#include <bits/stdc++.h>
using namespace std;
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
        date.clear();
        tree.clear();
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
    int n;
    while (cin >> n, n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(0);
        }
        node.build(v);
        int a, b;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            node.add_range(a, b, 1);
        }
        for (int i = 1; i < n; i++)
        {
            printf("%d ", node.quer(i));
        }
        cout << node.quer(n) << endl;
    }
    return 0;
}