#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> fa[5010];
int dp[5010];
int scz[5010];
int ez[5010];
const int mod = 80112002;
signed main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        scz[b]++;
        ez[b]++;
        fa[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!scz[i])
            dp[i] = 1;
    }
    while (true)
    {
        int f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!scz[i])
            {
                f = 1;
                for (int j = 0; j < fa[i].size(); j++)
                {
                    dp[fa[i][j]] += dp[i];
                    dp[fa[i][j]] %= mod;
                    scz[fa[i][j]]--;
                }
                scz[i]--;
            }
        }
        if (!f)
            break;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!fa[i].size() && ez[i])
        {
            ans += dp[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
}