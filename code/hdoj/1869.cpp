#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
typedef long long ll;
int mp[1000][1000];
int n, m;
void work()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                if (i == j)
                    mp[i][j] == 0;
                else
                    mp[i][j] = inf;
        }
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            if (u == v)
                continue;
            mp[u][v] = 1;
            mp[v][u] = 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mp[i][k] + mp[k][j] < mp[i][j])
                        mp[i][j] = mp[i][k] + mp[k][j];
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mp[i][j] > 7)
                {
                    fl = 1;
                    break;
                }
        }
        if (fl == 1)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
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