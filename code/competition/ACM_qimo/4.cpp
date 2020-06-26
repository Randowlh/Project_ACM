#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
ll tree[500000];
int n;
int cnt = 0;
int lowbit(int x)
{
    return x & -x;
}
int update(int x, int v)
{
    while (x <= n)
    {
        tree[x] += v;
        x += lowbit(x);
    }
    return 0;
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
void work()
{
    int m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= 110000; i++)
        {
            tree[i] = 0;
        }
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            update(i + 1, tmp);
        }
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            cout << get_range(a, b) << endl;
        }
    }
}
signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}