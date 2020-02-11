#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    int x;
    int y;
    bool operator<(node a){
        if(x==a.x){
            return y<a.y;
        }else
            return x < a.x;
    }
    bool operator==(node a){
        if(x==a.x&&y==a.y)
            return true;
        else
            return false;
    }
    bool operator!=(node a){
        if(*this==a){
            return false;
        }
        return true;
    }
} nu;
int biao[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, m, k;
int mp[110][110];
node pr[110][110];
int ans = 0;
int book[110][110];
bool check(int x, int y){
    if(x<1||x>n){
        return false;
    }
    if(y<1||y>m)
        return false;
    if(mp[x][y]==0)
        return false;
    return true;
}
bool dfs(int x,int y){
    for (int i = 0; i < 4;i++){
        if(check(x+ biao[i][0],y+ biao[i][1])&&!book[x+biao[i][0]][y + biao[i][1]]){
            book[x + biao[i][0]][y + biao[i][1]] = 1;
            book[x][y] = 1;
            if (pr[x + biao[i][0]][y + biao[i][1]] == nu || dfs(pr[x + biao[i][0]][y + biao[i][1]].x, pr[x + biao[i][0]][y + biao[i][1]].y))
            {
                node a,b;
                a.x = x;
                a.y = y;
                b.x = x + biao[i][0];
                b.y = y + biao[i][1];
                pr[x][y] = b;
                pr[x + biao[i][0]][y + biao[i][1]] = a;
                return true;
            }
        }
    }
    return false;
}
void xyl(){
    ans = 0;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            pr[i][j] = nu;
        }
    }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= n; k++)
                    for (int q = 1; q <= m; q++)
                        book[k][q] = 0;
                if(check(i,j)&&dfs(i, j))
                    ans++;
            }
        }
    return;
}
void work()
{
    while(cin>>n >> m){
        if(n==m&&m==0){
            break;
        }
        cin >> k;
        memset(mp, 1, sizeof(mp));
        int x, y;
        for (int i = 0; i < k; i++)
        {
            cin>>x>>y;
            mp[x][y] = 0;
        }
        xyl();
        cout<<ans/2<<endl;
        memset(book, 0, sizeof(book));
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                if(!book[i][j]&&pr[i][j]!=nu){
                    book[i][j] = 1;
                    cout << "（" << i << "," << j << "）-（" << pr[i][j].x << "," << pr[i][j].y << "）" << endl;
                    book[pr[i][j].x][pr[i][j].y] = 1;
                }
            }
        }
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    nu.x = -1;
    nu.y = -1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}