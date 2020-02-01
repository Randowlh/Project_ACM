#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
#define yes cout<<"yes"<<endl;
struct node
{
    int x;
    int y;
    int z;
};
int m, n, l, t;
int b[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int mp[1300][130][65];
bool book[1300][130][65];
bool check(int x,int y,int z){
    if(x<0||x>=m){
        return false;
    }
    if(y<0||y>=n)
    return false;
    if(z<0||z>=l)
    return false;
    if(book[x][y][z]!=0){
        return false;
    }
    if(!mp[x][y][z]){
        return false;
    }
    return true;
}
int bfs(int x, int y, int z)
{  
    int cnt=1;
    book[x][y][z]=1;
    node s;
    s.x=x;
    s.y=y;
    s.z=z;
    queue<node> q;
    q.push(s);
    while(!q.empty()){
        for(int i=0;i<6;i++){
            if(check(q.front().x+b[i][0],q.front().y+b[i][1],q.front().z+b[i][2])){
                book[q.front().x+b[i][0]][q.front().y+b[i][1]][q.front().z+b[i][2]]=1;
                cnt++;
                node x;
                x.x=q.front().x+b[i][0];
                x.y=q.front().y+b[i][1];
                x.z=q.front().z+b[i][2];
                q.push(x);
            }
        }
        q.pop();
    }
    return cnt;
}
void work()
{
    cin >> m >> n >> l >> t;
    for (int q = 0; q < l; q++)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mp[i][j][q]);
    }
    int ans=0;
    for (int q = 0; q < l; q++)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                if(book[i][j][q]==0&&mp[i][j][q]){
                   // yes
                    int k=bfs(i,j,q);
                   // yes
                    if(k>=t){
                        ans+=k;
                    }
                }
            }
    }
    cout<<ans<<endl;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}