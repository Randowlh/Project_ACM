#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int x;
    int y;
    int rx;
    int ry;
    int t;
    bool operator==(node a){
        return x==a.x&&y==a.y;
    }
    /* data */
};
int n, m;
int mp[100][100];
int b[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool check(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}
bool yidong(int rx, int ry, int cx, int cy, int dr)
{
    if (cx + b[dr][0] < 0 || cx + b[dr][0] >= n)
        return false;
    if (cy + b[dr][1] < 0 || cy + b[dr][1] >= m)
        return false;
    if (mp[cx + b[dr][0]][cy + b[dr][1]] == 1)
        return false;
    if (cx - b[dr][0] < 0 || cx - b[dr][0] >= n)
        return false;
    if (cy - b[dr][1] < 0 || cy - b[dr][1] >= m)
        return false;
    node e;
    e.x = cx - b[dr][0];
    e.y = cy - b[dr][1];
    node s;
    s.x = rx;
    s.y = ry;
    int book[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            book[i][j] = 0;
    mp[cx][cy] = 1;
    queue<node> qe;
    qe.push(s);
    book[rx][ry] = 1;
    while (!qe.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (check(qe.front().x + b[i][0], qe.front().y + b[i][1]) && mp[qe.front().x + b[i][0]][qe.front().y + b[i][1]] == 0&&book[qe.front().x + b[i][0]][qe.front().y + b[i][1]]==0)
            {   
                node x;
                x.x = qe.front().x + b[i][0];
                x.y = qe.front().y + b[i][1];
                book[x.x][x.y] = 1;
                qe.push(x);
            }
        }
        qe.pop();
    }
    mp[cx][cy] = 0;
    if (book[e.x][e.y] == 1)
    {
        return true;
    }
    else
        return false;
}
void work()
{
    int book[10][10][10][10];
    node end;
    node ren;
    node xiang;
    //  int n, m;
    cin >> n >> m;
    memset(book,0,sizeof(book));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
           // book[i][j] = 0;
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 2)
            {
                mp[i][j] = 0;
                xiang.x = i;
                xiang.y = j;
            }
            if (mp[i][j] == 3)
            {
                mp[i][j] = 0;
                end.x = i;
                end.y = j;
            }
            if (mp[i][j] == 4)
            {
                mp[i][j] = 0;
                ren.x = i;
                ren.y = j;
            }
        }
    queue<node> q;
    book[xiang.x][xiang.y][ren.x][ren.y] = 1;
    xiang.t = 0;
    xiang.rx=ren.x;
    xiang.ry=ren.y;
    ll ans = -1;
    q.push(xiang);
    while (!q.empty())
    {   if(ans!=-1)
        break;
        for (int i = 0; i < 4; i++)
        {
            if (yidong(q.front().rx, q.front().ry, q.front().x, q.front().y, i)&&book[q.front().x+b[i][0]][q.front().y+b[i][1]][q.front().x-b[i][0]][q.front().y-b[i][1]]==0)
            {
                if (q.front().x + b[i][0] == end.x && q.front().y + b[i][1] == end.y)
                {
                    ans = q.front().t + 1;
                    break;
                }
                node x;
                x.x = q.front().x + b[i][0];
                x.y = q.front().y + b[i][1];
                x.t = q.front().t + 1;
                x.rx=q.front().x;
                x.ry=q.front().y;
                book[q.front().x+b[i][0]][q.front().y+b[i][1]][q.front().x-b[i][0]][q.front().y-b[i][1]]=1;
                q.push(x);
            }
        }
        q.pop();
    }
    // for(int i=0;i<n;i++){
    // for(int j=0;j<m;j++)
    // printf("%5d",book[i][j]);
    // cout<<endl;
    // }
    cout << ans << endl;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}