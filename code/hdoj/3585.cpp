#include <bits/stdc++.h>
using namespace std;
int mp[2000][2000];
vector<int> R[2000], P[2000], X[2000];
int n, k;
int nw = 0;
bool Bron_Kerbosch(int t)
{
    if (R[t].size() + P[t].size() < k)
        return 0;
    if (R[t].size() >= k)
    {
        return 1;
    }
    if (!P[t].size() && !X[t].size())
    {
        if (R[t].size() >= k)
            return 1;
        else
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
            if (mp[P[t][i]][P[t][j]] >= nw)
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
        if (now != pivot)
        {
            if (mp[now][pivot] >= nw)
                continue;
        }
        R[t + 1] = R[t];
        R[t + 1].push_back(now);
        P[t + 1].clear();
        for (int j = 0; j < P[t].size(); j++)
        {
            if (P[t][j] && mp[P[t][j]][now] >= nw)
            {
                P[t + 1].push_back(P[t][j]);
            }
        }
        X[t + 1].clear();
        for (int j = 0; j < X[t].size(); j++)
        {
            if (mp[X[t][j]][now] >= nw)
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
    while (scanf("%d%d", &n, &k) != EOF)
    {
        vector<int> rd;
        vector<pair<int, int>> a;
        pair<int, int> x;
        a.push_back(make_pair(0, 0));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x.first, &x.second);
            a.push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                mp[i][j] = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
                mp[j][i] = mp[i][j];
                rd.push_back(mp[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            mp[i][i] = 0;
        }
        rd.push_back(0x7FFFFFFF);
        sort(rd.begin(), rd.end());
        int b = 0;
        int e = rd.size() - 1;
        while (b != e)
        {

            int mid = (e + b) >> 1;
            nw = rd[mid];
            R[0].clear();
            X[0].clear();
            P[0].clear();
            for (int i = 1; i <= n; i++)
            {
                P[0].push_back(i);
            }
            if (Bron_Kerbosch(0))
            {
                b = mid + 1;
            }
            else
            {
                e = mid;
            }
            //cout << b << ' ' << e << endl;
        }
        b--;
        printf("%.2f\n", sqrt(rd[b]));
    }
}