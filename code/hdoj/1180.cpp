#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
char mp[30][30];
int book[30][30];
int biao[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
struct node
{
    int x;
    int y;
    int t;
};
void work()
{
    int n, m;
    while (cin >> n >> m)
    {
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                book[i][j] = -1;
                if (mp[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                    continue;
                }
                if (mp[i][j] == 'T')
                {
                    ex = i;
                    ey = j;
                }
            }
        queue<node> q;
        node x;
        x.x = sx;
        x.t = 0;
        x.y = sy;
        q.push(x);
        book[sx][sx] = 0;
        while (!q.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                if (q.front().x + biao[i][0] >= 0 && q.front().x + biao[i][0] < n && q.front().y + biao[i][1] >= 0 && q.front().y + biao[i][1] < m)
                {
                    if (mp[q.front().x + biao[i][0]][q.front().y + biao[i][1]] != '*' && book[q.front().x + biao[i][0]][q.front().y + biao[i][1]] == -1)
                    {
                        if (mp[q.front().x + biao[i][0]][q.front().y + biao[i][1]] == '|')
                        {

                        }
                        else if (mp[q.front().x + biao[i][0]][q.front().y + biao[i][1]] == '-')
                        {
                            
                        }
                        else
                        {
                            node x;
                            x.x = q.front().x + biao[i][0];
                            x.y = q.front().y + biao[i][1];
                            book[q.front().x + biao[i][0]][q.front().y + biao[i][1]] = q.front().t + 1;
                            x.t = q.front().t + 1;
                            q.push(x);
                        }
                    }
                }
            }
            q.pop();
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}