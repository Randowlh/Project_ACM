#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y;
    bool operator==(node a)
    {
        if (x == a.x && y == a.y)
        {
            return true;
        }
        else
            return false;
    }
};
node link[101][101];
int n, m, dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
bool mp[101][101], book[101][101];
bool DFS(node a)
{
    node b;
    for (int i = 0; i < 4; ++i)
    {
        b.x = a.x + dir[i][0];
        b.y = a.y + dir[i][1];
        if (b.x <= 0 || b.y <= 0 || b.x > n || b.y > m || mp[b.x][b.y] || book[b.x][b.y])
            continue;
        book[b.x][b.y] = 1;
        if (link[b.x][b.y].x == 0 || DFS(link[b.x][b.y]))
        {
            link[b.x][b.y] = a;
            return true;
        }
    }
    return 0;
}
int main()
{
    while (cin >> n >> m)
    {
        if (n == m && m == 0)
            break;
        int k;
        cin >> k;
        memset(mp, 0, sizeof(mp));
        int x, y;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            mp[x][y] = 1;
        }
        int ans = 0;
        node nil;
        nil.x = 0;
        nil.y = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                link[i][j] = nil;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if ((i + j) & 1 || mp[i][j])
                    continue;
                memset(book, 0, sizeof(book));
                node a;
                a.x = i;
                a.y = j;
                if (DFS(a))
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (link[i][j] == nil)
                    continue;
                printf("(%d,%d)--(%d,%d)\n", i, j, link[i][j].x, link[i][j].y);
            }
        }
    }
}