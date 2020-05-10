#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
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
vector<int> tmp;
int n, m;
void work()
{
    tmp.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        tmp.push_back(0);
    }
    node.build(tmp);
    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        node.add_range(l, r, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        tmp[i - 1] = node.quer(i);
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    ll ans = 0;
    int now = n;
    for (int i = 0; i < n; i++)
    {
        ans += now * tmp[i];
        now--;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}