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
int n, m;
int b[4][3] = {{1, 0, 0}, {-1, 0, 1}, {0, 1, 2}, {0, -1, 3}};
char mp[110][110];
bool check(int x, int y)
{
    if (x < 0 && x >= n)
        return false;
    if (y < 0 && y >= m)
        return false;
    return true;
}
void work()
{
    int book[110][110];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            book[i][j] = inf;
        }
    node s, e;
    int k;
    cin >> k >> s.y >> s.x >> e.y >> e.x;
    node x;
    s.x--;
    s.y--;
    e.x--;
    e.y--;
    if(mp[s.x][s.y]=='*'){
    cout<<"no"<<endl;
    return;
    }
    if(s.x==e.x&&e.y==s.y){
        cout<<"yes"<<endl;
        return;
    }
    x.x = s.x;
    x.y = s.y;
    x.t = 0;
    x.s = -1;
    book[s.x][s.y] = 0;
    priority_queue<node> q;
    q.push(x);
    while (!q.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (check(q.top().x + b[i][0], q.top().y + b[i][1]) && book[q.top().x + b[i][0]][q.top().y + b[i][1]] >= q.top().t && mp[q.top().x + b[i][0]][q.top().y + b[i][1]] == '.' )
            {
                node x;
                x.x = q.top().x + b[i][0];
                x.y = q.top().y + b[i][1];
                if (q.top().s != b[i][2])
                    x.t=q.top().t+1;
                else
                x.t=q.top().t;
                x.s=b[i][2];
                q.push(x);
                book[x.x][x.y]=min(book[x.x][x.y],x.t);
            }
        }
        q.pop();
    }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++)
//         if(book[i][j]!=inf)
//         printf("%5d",book[i][j]);
//         else
//         printf("%5d",-1);
//         cout<<endl;
// }
    if(book[e.x][e.y]-1>=k+1){
        cout<<"no"<<endl;
    }else cout<<"yes"<<endl;
    // cout<<book[e.x][e.y]<<endl;
    return ;
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