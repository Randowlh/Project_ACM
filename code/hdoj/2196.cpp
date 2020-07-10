#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> mp[11000];
int n;
int dp[11000][3];
int tp[11000];
void dfs1(int now, int f)
{
    dp[now][0] = 0;
    dp[now][1] = 0;
    for (int i = 0; i < mp[now].size(); i++)
    {
        int &to = mp[now][i].first;
        if (to == f)
            continue;
        dfs1(to, now);
        if (dp[now][0] < dp[to][0] + mp[now][i].second)
        {
            dp[now][0] = dp[to][0] + mp[now][i].second;
            tp[now] = to;
        }
    }
    for (int i = 0; i < mp[now].size(); i++)
    {
        int to = mp[now][i].first;
        if (to == f || to == tp[now])
            continue;
        dp[now][1] = max(dp[now][1], dp[to][0] + mp[now][i].second);
    }
    return;
}
void dfs2(int now, int f)
{
    for (int i = 0; i < mp[now].size(); i++)
    {
        int &to = mp[now][i].first;
        if (to == f)
            continue;
        if (to == tp[now])
            dp[to][2] = max(dp[now][2], dp[now][1]) + mp[now][i].second;
        else
            dp[to][2] = max(dp[now][2], dp[now][0]) + mp[now][i].second;
        dfs2(to, now);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
        {
            mp[i].clear();
        }
        int a, b;
        for (int i = 2; i <= n; i++)
        {
            cin >> a >> b;
            mp[i].push_back(make_pair(a, b));
            mp[a].push_back(make_pair(i, b));
        }
        dfs1(1, -1);
        dfs2(1, -1);
        for (int i = 1; i <= n; i++)
            cout << max(dp[i][0], dp[i][2]) << endl;
    }
}