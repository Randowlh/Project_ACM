#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
int mp[330][330];
int dis[1000];
int n, m;
int ans = 0;
void Prim()
{
    int flag[1000];
    memset(flag, 1, sizeof(flag));
    memset(dis, inf, sizeof(dis));
    dis[1] = 0;
    int cnt = 0;
    while (cnt < n)
    {
        int mi = inf + 100;
        int mix = 0;
        for (int i = 1; i <= n; i++)
        {
            if (flag[i] && mi > dis[i])
            {
                mi = dis[i];
                mix = i;
            }
        }
        ans = max(mi, ans);
        for (int i = 1; i <= n; i++)
        {
            if (flag[i])
            {
                dis[i] = min(mp[mix][i], dis[i]);
            }
        }
        flag[mix] = 0;
        cnt++;
    }
    return;
}
int main()
{
    cin >> n >> m;
    memset(mp, inf, sizeof(mp));
    int w, u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> w >> u >> v;
        mp[w][u] = v;
        mp[u][w] = v;
    }
    Prim();
    cout << n - 1 << ' ' << ans << endl;
    return 0;
}