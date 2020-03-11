#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> R[300], P[300], X[300];
int mp[300][300];
vector<int> ma;
int ans = 0;
int n;
bool Bron_Kerbosch(int t)
{
    if (!P[t].size() && !X[t].size())
    {
        if (ma.size() < R[t].size())
        {
            ma.clear();
            ma = R[t];
        }
        return 0;
    }
    if (P[t].empty())
        return 0;
    int pivot = P[t][0];
    int max = -1;
    for (int i = 0; i < P[t].size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < P[t].size(); j++)
        {
            if (mp[P[t][i]][P[t][j]])
            {
                cnt++;
            }
        }
        if (max < cnt)
        {
            pivot = P[t][i];
            max = cnt;
        }
    }
    for (int i = 0; i < P[t].size(); i++)
    {
        int now = P[t][i];
        if (mp[now][pivot])
            continue;
        R[t + 1] = R[t];
        R[t + 1].push_back(now);
        P[t + 1].clear();
        for (int j = 0; j < P[t].size(); j++)
        {
            if (P[t][j] != 0 && mp[P[t][j]][now])
            {
                P[t + 1].push_back(P[t][j]);
            }
        }
        X[t + 1].clear();
        for (int j = 0; j < X[t].size(); j++)
        {
            if (mp[X[t][j]][now])
            {
                X[t + 1].push_back(X[t][j]);
            }
        }
        if (Bron_Kerbosch(t + 1))
        {
            return 1;
        }
        P[t][i] = 0;
        X[t].push_back(now);
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int m;
        cin >> n >> m;
        int w, v;
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin >> w >> v;
            mp[w][v] = 0;
            mp[v][w] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            mp[i][i] = 0;
        }
        ma.clear();
        R[0].clear();
        X[0].clear();
        P[0].clear();
        for (int i = 1; i <= n; i++)
        {
            P[0].push_back(i);
        }
        Bron_Kerbosch(0);
        cout << ma.size() << endl;
        for (int i = 0; i < ma.size(); i++)
        {
            cout << ma[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}