#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

int mp[510][510];
int flag[510], dis[510];
int m, n;

void dijkstra(int v)
{
    for (int i = 1; i <= n; i++)
        dis[i] = mp[v][i];
    flag[v] = 1;
    while (1)
    {
        int min = inf, k = -1;
        for (int i = 1; i <= n; i++)
            if (!flag[i] && min > dis[i])
            {
                min = dis[i];
                k = i;
            }
        if (k == -1)
            break;
        flag[k] = 1;
        for (int i = 1; i <= n; i++)
            if (!flag[i] && dis[i] > min + mp[k][i])
                dis[i] = min + mp[k][i];
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n + m == 0)
            break;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < 510; i++)
            for (int j = 0; j < 510; j++)
                mp[i][j] = inf;
        for (int i = 0; i < 510; i++)
            mp[i][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x, a = (i - 1) * (m + 1) + j;
                char dir;
                scanf("%d %c", &x, &dir);
                if (x == 0)
                    continue;
                if (dir == '>')
                    mp[a][a + 1] = 2520 / x;
                else if (dir == '<')
                    mp[a + 1][a] = 2520 / x;
                else if (dir == '*')
                    mp[a][a + 1] = mp[a + 1][a] = 2520 / x;
            }
            for (int j = 1; j <= m + 1; j++)
            {
                int x, a = (i - 1) * (m + 1) + j;
                char dir;
                scanf("%d %c", &x, &dir);
                if (x == 0)
                    continue;
                if (dir == 'v')
                    mp[a][a + 1 + m] = 2520 / x;
                else if (dir == '^')
                    mp[a + 1 + m][a] = 2520 / x;
                else if (dir == '*')
                    mp[a][a + 1 + m] = mp[a + 1 + m][a] = 2520 / x;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            int x, a = n * (m + 1) + j;
            char dir;
            scanf("%d %c", &x, &dir);
            if (x == 0)
                continue;
            if (dir == '>')
                mp[a][a + 1] = 2520 / x;
            else if (dir == '<')
                mp[a + 1][a] = 2520 / x;
            else if (dir == '*')
                mp[a][a + 1] = mp[a + 1][a] = 2520 / x;
        }
        n = (n + 1) * (m + 1);
        dijkstra(1);
        if (dis[n] < inf)
            printf("%d blips\n", dis[n]);
        else
            printf("Holiday\n");
    }
    return 0;
}