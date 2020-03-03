#include <bits/stdc++.h>
using namespace std;
int mp[110][110];
int n, m;
void Floyd_Warshall()
{
    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 0; i <= n; i++)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}
int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
            {
                if (i == j)
                    mp[i][i] = 0;
                else
                    mp[i][j] = 9999999;
            }
        int w, u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> w >> u >> v;
            mp[w][u] = min(mp[w][u], v);
            mp[u][w] = min(mp[u][w], v);
        }
        Floyd_Warshall();
        cout << mp[1][n] << endl;
    }
    return 0;
}