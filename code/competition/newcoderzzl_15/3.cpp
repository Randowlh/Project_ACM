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
vector<int> mp[251000];
int dfn[251000];
int fa[251000];
set<int> s;
int n, m;
int dfs(int x)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(dfn[x] ^ (1 << i));
    sort(v.begin(), v.end());
    sort(mp[x].begin(), mp[x].end());
    for (int i = 0; i < mp[x].size(); i++)
    {
    }
}
void work()
{
    //int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    fa[1] = -1;
    dfn[1] = 0;
    dfs(1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}