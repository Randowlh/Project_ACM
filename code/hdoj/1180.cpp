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
    bool operator<(node a) const{
        return t>a.t;
    }
};
int n, m;
bool check(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
void work()
{
    // int n, m;
    while (cin >> n >> m)
    {
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                book[i][j] = inf;
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
        //  cout<<sx<<" "<<sy<<endl;
        priority_queue<node> q;
        node x;
        x.x = sx;
        x.t = 0;
        x.y = sy;
        q.push(x);
        book[sx][sy] = 0;
        while (!q.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                if (check(q.top().x + biao[i][0], q.top().y + biao[i][1]))
                {
                    if (mp[q.top().x + biao[i][0]][q.top().y + biao[i][1]] != '*' && book[q.top().x + biao[i][0]][q.top().y + biao[i][1]] > q.top().t + 1)
                    {
                        if (mp[q.top().x + biao[i][0]][q.top().y + biao[i][1]] == '|')
                        {
                            node x;
                            x.x = q.top().x + biao[i][0] * 2;
                            x.y = q.top().y + biao[i][1] * 2;
                            if (check(x.x, x.y) && mp[x.x][x.y] != '*')
                            {
                                if (i+q.top().t % 2 == 0)
                                {
                                    x.t = q.top().t + 2;
                                }
                                else
                                    x.t = q.top().t + 1;
                                if (book[x.x][x.y] > x.t)
                                {
                                    book[x.x][x.y] = x.t;
                                    q.push(x);
                                }
                            }
                        }
                        else if (mp[q.top().x + biao[i][0]][q.top().y + biao[i][1]] == '-')
                        {
                            node x;
                            x.x = q.top().x + biao[i][0] * 2;
                            x.y = q.top().y + biao[i][1] * 2;
                            if (check(x.x, x.y) && mp[x.x][x.y] != '*')
                            {
                                if (i+q.top().t % 2 == 1)
                                {
                                    x.t = q.top().t + 2;
                                }
                                else
                                    x.t = q.top().t + 1;
                                if (book[x.x][x.y] > x.t)
                                {
                                    book[x.x][x.y] = x.t;
                                    q.push(x);
                                }
                            }
                        }
                        else
                        {
                            node x;
                            x.x = q.top().x + biao[i][0];
                            x.y = q.top().y + biao[i][1];
                            x.t = q.top().t + 1;
                            if (book[x.x][x.y] > x.t)
                            {
                                book[x.x][x.y] = x.t;
                                q.push(x);
                            }
                        }
                    }
                }
            }
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //         if (book[i][j] == inf)
            //             cout << -1 << "  ";
            //         else
            //             cout << book[i][j] << "  ";
            //     cout << endl;
            // }
            // cout << endl;
            q.pop();
        }
        if (book[ex][ey] == inf)
            cout << -1 << endl;
        else
            cout << book[ex][ey] << endl;
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