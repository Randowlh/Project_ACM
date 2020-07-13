#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
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
vector<int> ans;
vector<int> mp[200010];
int fa[200010];
void dfs(int x)
{
    if (mp[x].size() == 1)
    {
        ans.push_back(x);
        return;
    }
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] == fa[x])
            continue;
        fa[mp[x][i]] = x;
        dfs(mp[x][i]);
    }
}
void work()
{
    int n;
    cin >> n;
    int a, b;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i].size() >= 2)
        {
            root = i;
            break;
        }
    }
    fa[root] = -1;
    dfs(root);
    cout << (ans.size() + 1) / 2 << endl;
    for (int i = 0; i <= (ans.size() - 1) / 2; i++)
    {
        cout << ans[i] << ' ' << ans[i + ans.size() / 2] << endl;
    }
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