#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
int biao[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct node
{
    int x;
    int y;
    int t;
    friend bool operator<(node n1, node n2)
    {
        return n2.t < n1.t;
    }
} tmp;
char maap[300][300];
int book[300][300];
priority_queue<node> pee;
int main()
{
    //freopen("a.in", "r", stdin);
    int n, m;
    //cin>>t
    while (cin >> n >> m)
    {
        memset(maap, 0, sizeof(maap));
        memset(book, 0, sizeof(book));
        for (int i = 0; i < n; i++)
        {
            cin >> maap[i];
        }
        //int sx = -1;
        //int sy = -1;
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maap[i][j] == 'a')
                {
                    tmp.x = i;
                    tmp.y = j;
                }
                if (maap[i][j] == 'r')
                {
                    l++;
                }
            }
        }
        int flag=0;
        tmp.t = 0;
        pee.push(tmp);
        book[tmp.x][tmp.y] = 1;
        int maxt = 99999;
        while (!pee.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                if (pee.top().x + biao[i][0] >= 0 && pee.top().x + biao[i][0] < n && pee.top().y + biao[i][1] >= 0 && pee.top().y + biao[i][1] < m && book[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] == 0 && maap[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] != '#')
                {
                    if (maap[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] == 'r')
                    {
                        l--;
                        maxt = min(maxt, pee.top().t + 1);
                        node a;
                        book[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] = 1;
                        a.t = pee.top().t + 1;
                        a.x = pee.top().x + biao[i][0];
                        a.y = pee.top().y + biao[i][1];
                        pee.push(a);
                        flag=1;
                    }
                    else if (maap[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] == 'x')
                    {
                        node a;
                        book[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] = 1;
                        a.t = pee.top().t + 2;
                        a.x = pee.top().x + biao[i][0];
                        a.y = pee.top().y + biao[i][1];
                        pee.push(a);
                    }
                    else
                    {
                        node a;
                        book[pee.top().x + biao[i][0]][pee.top().y + biao[i][1]] = 1;
                        a.t = pee.top().t + 1;
                        a.x = pee.top().x + biao[i][0];
                        a.y = pee.top().y + biao[i][1];
                        pee.push(a);
                    }
                }
            }
            pee.pop();
        }
        if (flag==0)
        {
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
        else
        {
            cout << maxt << endl;
        }
    }
    return 0;
}
