#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
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

public:
    void add(int x, int v)
    {
        while (x <= n)
        {
            tree[x] += v;
            x += lowbit(x);
        }
        return;
    }
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
void work()
{
    int n, m;
    cin >> n >> m;
    string tmp;
    ll ans[300];
    memset(ans, 0, sizeof(ans));
    vector<int> v;
    cin >> tmp;
    int t;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    vector<int> te;
    te.resize(n + 1);
    node.build(te);
    for (int i = 0; i < m; i++)
    {
        node.add_range(1, v[i], 1);
    }
    for (int i = 0; i < n; i++)
    {
        ans[tmp[i]] += node.quer(i + 1);
        ans[tmp[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}