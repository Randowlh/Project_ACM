#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int mp[200][200];
vector<int> R[200], P[200], X[200];
int ans = 0;
int n, m;
bool Bron_Kerbosch(int t)
{
    if (!P[t].size() && !X[t].size())
    {
        ans++;
        if (ans > 1000)
        {
            return 1;
        }
        return 0;
    }
    if (P[t].empty())
        return 0;
    int pivot = P[t][0];
    int max = 0;
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
            if (P[t][j] && mp[P[t][j]][now])
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
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(mp, 0, sizeof(mp));
        int w, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &w, &v);
            mp[w][v] = 1;
            mp[v][w] = 1;
        }
        P[0].clear();
        for (int i = 1; i <= n; i++)
        {
            P[0].push_back(i);
        }
        R[0].clear();
        X[0].clear();
        ans = 0;
        Bron_Kerbosch(0);
        if (ans > 1000)
        {
            printf("Too many maximal sets of friends.\n");
        }
        else
            printf("%d\n", ans);
    }
    return 0;
}