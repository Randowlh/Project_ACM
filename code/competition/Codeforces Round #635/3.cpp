#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
vector<int> mp[200010];
int earn[200010];
int book[200010];
int dfs(int now, int step)
{
    int ans = 0;
    int f = 0;
    for (int i = 0; i < mp[now].size(); i++)
    {
        if (!book[mp[now][i]])
        {
            f = 1;
            book[mp[now][i]] = 1;
            ans += dfs(mp[now][i], step + 1);
        }
    }
    earn[now] = step - ans;
    if (f == 0)
        return 1;
    else
        return ans + 1;
}
void work()
{
    int n, k;
    cin >> n >> k;
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    book[1] = 1;
    dfs(1, 0);
    sort(earn + 1, earn + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += earn[i];
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