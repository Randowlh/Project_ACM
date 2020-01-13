#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int x;
    int y;
    int t;
    int s;
    bool operator<(node a) const
    {
        return t > a.t;
    }
};
int biao[4][3] = {{1, 0, 1}, {-1, 0, 2}, {0, 1, 3}, {0, -1, 4}};
int mp[1010][1010];
int book[1010][1010];
void work()
{
    int m, n;
    while (cin >> n >> m)
    {
        if (n == m && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &mp[i][j]);
                book[i][j] = -1;
            }
        }
        //int f;
        //  scanf("%d", &f);
        priority_queue<node> q;
        node s, e;
        int k;
        cin >> k;
        int x1, y1, x2, y2;
        for (int o = 0; o < k; o++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if ((x1==x2&&y1==y2)||mp[x1 - 1][y1 - 1] != mp[x2 - 1][y2 - 1]||mp[x1-1][y1-1]==0||mp[x2-1][y2-1]==0)
            {
                cout << "NO" << endl;
                continue;
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    book[i][j] = -1;
          //  f = mp[x1 - 1][y1 - 1];
            s.x = x1 - 1;
            s.y = y1 - 1;
            e.x = x2 - 1;
            e.y = y2 - 1;
            s.t = 0;
            s.s = -1;
            q.push(s);
            book[s.x][s.y] = 0;
            while (!q.empty())
            { //cout<<"YRd"<<endl;
                for (int i = 0; i < 4; i++)
                {
                    if (q.top().x + biao[i][0] < n && q.top().y + biao[i][1] < m && q.top().x + biao[i][0] >= 0 && q.top().y + biao[i][1] >= 0 && book[q.top().x + biao[i][0]][q.top().y + biao[i][1]] == -1 && (mp[q.top().x + biao[i][0]][q.top().y + biao[i][1]] == 0||(q.top().x+biao[i][0]==e.x&&q.top().y+biao[i][1]==e.y)))
                    {
                        if (biao[i][2] == q.top().s)
                        {
                            node x;
                            x.x = q.top().x + biao[i][0];
                            x.y = q.top().y + biao[i][1];
                            x.s = biao[i][2];
                            x.t = q.top().t;
                            book[x.x][x.y] = x.t;
                            q.push(x);
                        }
                        else
                        {
                            node x;
                            x.x = q.top().x + biao[i][0];
                            x.y = q.top().y + biao[i][1];
                            x.s = biao[i][2];
                            x.t = q.top().t + 1;
                            book[x.x][x.y] = x.t;
                            q.push(x);
                        }
                    }
                }
                q.pop();
            }
            /*
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%5d",book[i][j]);
                }
                cout << endl;
            }
            */
            
            if (book[e.x][e.y] <= 3 && book[e.x][e.y] > 0)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return;
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