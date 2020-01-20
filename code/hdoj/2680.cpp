#include <bits/stdc++.h>
using namespace std;
const int inf = 10000000;
typedef long long ll;
int mp[1010][1010];
int dis[1010];
bool flag[1010];
int n, m, s;
void work()
{
    while (cin >> n >> m >> s)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)

                if (i == j)
                    mp[i][j] = 0;
                else
                    mp[i][j] = inf;

        int w, u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &w, &u, &v);
            mp[w][u] = min(mp[w][u], v);
        }/*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(mp[i][j]==inf){
                    cout<<-1<<' ';
                }else cout<<mp[i][j]<<' ';
            }
            cout<<endl;
        }*/
        vector<int> ed;
        cin >> w;
        int tmp;
        for (int i = 0; i < w; i++)
        {
            scanf("%d", &tmp);
            ed.push_back(tmp);
        }
        for (int i = 0; i <= n; i++)
        {
            dis[i] = inf;
            flag[i] = true;
        }
        dis[s] = 0;
        int cnt = 0;
        while (cnt <= n)
        {
            int mi = inf + 100;
            int mit = 0;
            for (int i = 0; i <= n; i++)
            {
                if (flag[i] && mi > dis[i])
                {
                    mi = dis[i];
                    mit = i;
                }
            }
          //  cout<<mit<<' '<<mi<<endl;
            for (int i = 0; i <= n; i++)
            {
                dis[i] = min(dis[i], dis[mit] + mp[i][mit]);
            }
            flag[mit] = false;
            cnt++;
        }
        int mi = inf + 100;
        for (int i = 0; i < ed.size(); i++)
        {  // cout<<ed[i]<<"sad"<<endl;
            mi = min(mi, dis[ed[i]]);
        }
        if (mi == inf)
        {
            cout << -1 << endl;
        }
        else
            cout << mi << endl;
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