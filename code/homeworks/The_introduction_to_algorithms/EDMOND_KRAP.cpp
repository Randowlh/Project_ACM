#include <bits/stdc++.h>
using namespace std;
int pr[220];
int mp[220][220];
int flow[2020];
int m, n;
int bfs(int s, int e)
{
    memset(pr, -1, sizeof(pr));
    queue<int> q;
    q.push(s);
    flow[s] = 0x7FFFFFFF;
    pr[s] = 0;
    while (!q.empty())
    {
        int now = q.front();
        if (q.front() == e)
            break;
        for (int i = 1; i <= n; i++)
        {
            if (i != s && i != now && mp[now][i] && pr[i] == -1)
            {
                q.push(i);
                flow[i] = min(mp[now][i], flow[now]);
                pr[i] = now;
            }
        }
        q.pop();
    }
    if (pr[e] == -1)
        return pr[e];
    return flow[e];
}
int Edmond_Karpint(int s, int e)
{
    int ans = 0;
    int delita;
    while (true)
    {
        delita = bfs(s, e);
        if (delita == -1)
            break;
        int now = e;
        while (now != s)
        {
            mp[pr[now]][now] -= delita;
            mp[now][pr[now]] += delita;
            now = pr[now];
        }
        ans += delita;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    while (cin >> m >> n)
    {
        int w, u, v;
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < m; i++)
        {
            cin >> w >> u >> v;
            mp[w][u] += v;
        }
        cout << Edmond_Karpint(1, n) << endl;
    }
}