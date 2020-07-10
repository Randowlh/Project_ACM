#include <bits/stdc++.h>
using namespace std;
vector<int> mp[11000];
int date[11000];
int dp[11000][2];
void dfs(int now)
{
    dp[now][1] = 0;
    dp[now][0] = 0;
    if (mp[now].empty())
    {
        dp[now][1] = date[now];
        dp[now][0] = 0;
    }
    else
    {
        for (int i = 0; i < mp[now].size(); i++)
        {
            dfs(mp[now][i]);
            dp[now][0] += max(dp[mp[now][i]][1], dp[mp[now][i]][0]);
            dp[now][1] += dp[mp[now][i]][0];
        }
        dp[now][1] += date[now];
    }
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> date[i];
            mp[i].clear();
        }
        set<int> s;
        int u, v;
        while (cin >> u >> v)
        {
            // cout << u << ' ' << v << endl;
            if (u == 0 && v == 0)
                break;
            mp[v].push_back(u);
            s.insert(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (s.count(i) == 0)
            {
                dfs(i);
                cout << max(dp[i][0], dp[i][1]) << endl;
                break;
            }
        }
    }
}