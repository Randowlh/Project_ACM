#include <bits/stdc++.h>
using namespace std;
const int inf = 10000000;
typedef long long ll;
int mp[110][110];
int n, m;
int dis[110];
int power[110];
bool flag[110];
int dp[100000];
ll tol;
void work()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            mp[i][j] = inf;
        }
    for (int i = 0; i <= n; i++){
        mp[i][i] = 0;
        //cout<<1<<endl;
    }
    int u, w, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &w, &v);
        mp[u][w] = min(mp[u][w], v);
        mp[w][u] = mp[u][w];
    }
    tol = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &power[i]);
        tol += power[i];
    }
    for (int i = 0; i <= n; i++)
    {
        flag[i] = true;
        dis[i] = inf;
    }
    power[0] = 0;
    dis[0] = 0;
    int cnt = 0;
    //cout<<"no"<<endl;
    while (cnt <= n )
    {   
        int mx = inf + 100;
        int mix = 0;
        for (int i = 0; i <= n; i++)
        {
            if (flag[i] && dis[i] < mx)
            {
                mx = dis[i];
                mix = i;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            dis[i] = min(dis[i], dis[mix] + mp[mix][i]);
        }
        flag[mix] = false;
        cnt++;
    }
    //cout<<"yes"<<endl;
    int mx = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dis[i] != inf)
        {
            mx += dis[i];
        }
    }
        for (int j = 0; j <= mx; j++)
            dp[j] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = mx; j >= dis[i]; j--)
        {
            if (j >= dis[i])
            {
                dp[j] = max(dp[j], dp[j - dis[i]] + power[i]);
            }
        }
    }
    tol /= 2;
    tol++;
    int fl = 1;
    for (int i = 0; i <= mx; i++)
    {
        if (dp[i] >= tol)
        {
            cout << i << endl;
            fl = 0;
            break;
        }
    }

    if (fl)
    {
        cout << "impossible" << endl;
    }
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
   // cout<<"tes"<<endl;
    while (t--)
    {
        work();
    }
    return 0;
}