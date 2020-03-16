#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
const int MAXN = 2510;
int n, m;
int mp[MAXN][MAXN];
int dis[MAXN];
int Dijkstra(int s, int t)
{
    memset(dis, 1000000, sizeof(dis));
    dis[s] = 0;
    int flag[MAXN];
    memset(flag, 1, sizeof(flag));
    int cnt = 0;
    while (cnt < n)
    {
        int mi = inf + 100;
        int mix = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] < mi && flag[i])
            {
                mi = dis[i];
                mix = i;
            }
        }
        flag[mix] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (flag[i])
            {
                dis[i] = min(dis[i], mp[i][mix] + dis[mix]);
            }
        }
        cnt++;
    }
    return dis[t];
}
int main()
{
    int s, t;
    cin >> n >> m >> s >> t;
    memset(mp, 1000000, sizeof(mp));
    int u, w, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> w >> v;
        mp[u][w] = v;
        mp[w][u] = v;
    }
    cout << Dijkstra(s, t) << endl;
    return 0;
}