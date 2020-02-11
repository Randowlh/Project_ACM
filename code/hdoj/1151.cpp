#include<bits/stdc++.h>
using namespace std;
int mp[150][150];
int n, m, k;
int ans = 0;
int pr[150];
int book[150];
bool dfs(int x){
    for (int i = 1; i <= n;i++){
        if(mp[x][i]&&!book[i]){
            book[i] = 1;
            if(pr[i]==-1||dfs(pr[i])){
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
     ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= n;i++){
        memset(book, 0, sizeof(book));
        if (dfs(i)){
            ans++;
        }
    }
}
void work()
{
    cin >> n >> m;
    int u, w;
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> w;
        mp[u][w] = 1;
    }
    xyl();
    cout << n-ans << endl;
}
int main()
{
 //   freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        work();
    }
    return 0;
}