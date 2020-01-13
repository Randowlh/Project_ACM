#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
char mp[30][30];
int book[30][30];
int biao[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
    int x;
    int y;
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
        x.x=sx;
        x.y=sy;
        q.push(x);
        book[sx][sx]=0;
        while(!q.empty()){
            for(int i=0;i<4;i++){
                if(q.front().x+biao[i][0]>=0&&q.front().x+biao[i][0]<n&&)
            }
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