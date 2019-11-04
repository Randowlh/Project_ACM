#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    //int t;
    int l;
} queue[100010];
int biao[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int map[10][10];
int n, m;
int tail;
int head;
//int ltime[10][10][7];
int time1[11][11][10];
//int book[10][10][7];
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> n >> m;
        int sx, sy;
        int ex, ey;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] == 3)
                {
                    ex = i;
                    ey = j;
                }
                // book[i][j]==0;
            }
        }
        head = 0;
        tail = 0;
        queue[tail].x = sx;
        queue[tail].y = sy;
        //queue[tail].t=0;
        queue[tail].l = 6;
        tail++;
        time1[sx][sy][6] = 0;
        //ltime[sx][sy]=6;
        //book[sx][sy]=1;
        memset(time1, 9999, sizeof(time1));
        time1[sx][sy][6] = 0;
        while (tail ^ head)
        {
            if (queue[head].l > 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (queue[head].x + biao[i][0] >= 0 && queue[head].x + biao[i][0] < n && queue[head].y + biao[i][1] >= 0 && queue[head].y + biao[i][1] < m && map[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]] != 0)
                    {
                        if (map[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]] == 4)
                        {
                            if (time1[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]][6] > time1[queue[head].x][queue[head].y][queue[head].l] + 1)
                            {
                                time1[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]][6] = time1[queue[head].x][queue[head].y][queue[head].l] + 1;
                                queue[tail].x = queue[head].x + biao[i][0];
                                queue[tail].y = queue[head].y + biao[i][1];
                                queue[tail].l = 6;
                                tail++;
                            }
                        }else
                        if (time1[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]][queue[head].l - 1] > time1[queue[head].x][queue[head].y][queue[head].l] + 1)
                        {
                            time1[queue[head].x + biao[i][0]][queue[head].y + biao[i][1]][queue[head].l - 1] = time1[queue[head].x][queue[head].y][queue[head].l] + 1;
                            queue[tail].x = queue[head].x + biao[i][0];
                            queue[tail].y = queue[head].y + biao[i][1];
                            queue[tail].l = queue[head].l - 1;
                            tail++;
                        }
                    }
                }
            }
           // printf("%d %d %d %d\n", queue[head].x, queue[head].y,queue[head].l,time1[queue[head].x][queue[head].y][queue[head].l]);
            head++;
        }
        int ans = 9999;
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int anss = 99;
                for (int k = 1; k < 7; k++)
                {
                    anss = min(time1[i][j][k], anss);
                }
                printf("%2d ", anss);
            }
            cout << endl;
        }*/
        for (int i = 1; i < 7; i++)
        {
            ans = min(time1[ex][ey][i], ans);
        }
        //cout<<time1[2][0][5]<<' '<<time1[3][0][4]<<time1[3][0][3]<<endl;
        if (ans == 9999)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans <<  endl;
        }
    }
    return 0;
}