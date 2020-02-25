#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int n, m;
int pr[20];
int flow[20];
int mp[20][20];
int cnt = 0;
int bfs(int s, int e)
{
    memset(pr, -1, sizeof(pr));
    queue<int> q;
    q.push(s);
    pr[s] = 0;
    flow[s] = inf;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == e)
            break;
        for (int i = 1; i <= n; i++)
        {
            if (i != s && i != now && mp[now][i] && pr[i] == -1)
            {
                q.push(i);
                pr[i] = now;
                flow[i] = min(flow[now], mp[now][i]);
            }
        }
    }
    if (pr[e] == -1)
    {
        return -1;
    }
    else
        return flow[e];
}
int EK(int s, int e)
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
void work()
{
    cnt++;
    memset(mp, 0, sizeof(mp));
    cin >> n >> m;
    int u, w, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> w >> v;
        mp[u][w] += v;
    }
    cout << "Case " << cnt << ": ";
    cout << EK(1, n) << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}