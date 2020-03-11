#include <bits/stdc++.h>
using namespace std;
vector<int> R[300], P[300], X[300];
int mp[300][300];
int ans = 0;
int n;
bool Bron_Kerbosch(int t)
{
    if (!P[t].size() && !X[t].size())
    {
        ans = max(ans, (int)R[t].size());
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
    // freopen("in.txt", "r", stdin);
    while (cin >> n, n)
    {
        vector<int> pns;
        string tmp;
        getchar();
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++)
        {
            getline(cin, tmp);
            pns.push_back(tmp[0]);
            for (int j = 2; j < tmp.size(); j++)
            {
                mp[tmp[0]][tmp[j]] = 1;
                mp[tmp[j]][tmp[0]] = 1;
            }
        }
        ans = 0;
        R[0].clear();
        P[0].clear();
        X[0].clear();
        for (int i = 0; i < pns.size(); i++)
        {
            P[0].push_back(pns[i]);
        }
        Bron_Kerbosch(0);
        if (ans == 1)
            cout << ans << " channel needed." << endl;
        else
            cout << ans << " channels needed." << endl;
    }
    return 0;
}