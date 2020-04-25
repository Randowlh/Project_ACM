#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int M[1100][1100];
vector<int> mp[1100];
int dis[1100];
bool flag[1100];
int dp[1100];
int n, m;
void dij(int s)
{
    dis[s] = 0;
    int cnt = 0;
    while (cnt < n)
    {
        int mi = inf + 100LL;
        int mix = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!flag[i] && dis[i] < mi)
            {
                mi = dis[i];
                mix = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            dis[i] = min(dis[i], dis[mix] + M[mix][i]);
        }
        flag[mix] = true;
        cnt++;
    }
}
int dfs(int x)
{
    if (dp[x] != -1)
        return dp[x];
    int ans = 0;
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (dis[x] > dis[mp[x][i]])
        {
            int t = dfs(mp[x][i]);
            ans += t;
        }
    }
    dp[x] = ans;
    return ans;
}
void work()
{
    while (cin >> n, n)
    {
        cin >> m;
        int w, u, v;
        for (int i = 0; i <= n; i++)
        {
            flag[i] = false;
            dis[i] = inf;
            dp[i] = -1;
            mp[i].clear();
            for (int j = 0; j <= n; j++)
            {
                M[i][j] = inf;
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin >> w >> u >> v;
            M[w][u] = v;
            mp[w].push_back(u);
            mp[u].push_back(w);
            M[u][w] = v;
        }
        dp[2] = 1;
        dij(2);
        cout << dfs(1) << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}