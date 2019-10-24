#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int biao[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int map[10][10];
int escape;
int sx;
int sy;
int ex;
int ey;
int n, m, t;
int book[10][10];
void dfs(int x, int y, int a)
{
    if (a == t && x == ex && y == ey)
    {
        escape = 1;
        return;
    }
    else if (x == ex && y == ey)
    {
        return;
    }
    if (escape == 1)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (x + biao[i][0] < n && x + biao[i][0] >= 0 && y + biao[i][1] < m && y + biao[i][1] >= 0 && book[x + biao[i][0]][y + biao[i][1]] == 0 && map[x + biao[i][0]][y + biao[i][1]] == 1)
        {
            book[x + biao[i][0]][y + biao[i][1]] = 1;
            dfs(x + biao[i][0], y + biao[i][1], a + 1);
            book[x + biao[i][0]][y + biao[i][1]] = 0;
        }
    }
    return;
}
int main()
{
    char tmp;
    while (true)
    {
        escape = 0;
        memset(book, 0, sizeof(book));
        memset(map, 0, sizeof(map));
        scanf("%d%d%d", &n, &m, &t);
        if (n == 0 && m == 0 && t == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> tmp;
                if (tmp == 'S')
                {
                    sx = i;
                    sy = j;
                    map[i][j] = 1;
                }
                else if (tmp == 'D')
                {
                    ex = i;
                    ey = j;
                    map[i][j] = 1;
                }
                else if (tmp == 'X')
                {
                    map[i][j] == 0;
                }
                else if (tmp == '.')
                    map[i][j] = 1;
            }
        }
        book[sx][sy] = 1;
        dfs(sx, sy, 0);
        if (escape == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}