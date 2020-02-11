#include <bits/stdc++.h>
using namespace std;
int mp[1000][1000];
int lk[1000];
int book[1000];
int n, m, k;
int ans = 0;
int dfs(int x)
{
    for (int i = 0; i < m; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (lk[i] == -1 || dfs(lk[i]))
            {
                lk[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    memset(lk, -1, sizeof(lk));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            book[j] = 0;
        }
        if (dfs(i))
            ans++;
    }
}
int main()
{
 //   freopen("in.txt", "r", stdin);
    while (cin >> n)
    {
        if (n == 0)
            break;
            ans=0;
        cin >> m >> k;
        int u, w, v;
        memset(mp,0, sizeof(mp));
        for (int i = 0; i < k; i++)
        {
            cin >> v >> w >> u;
            if (w && u)
            {
                mp[w][u] = 1;
            }
        }
    xyl();
    cout << ans << endl;
    }
    return 0;
}