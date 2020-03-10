#include <bits/stdc++.h>
using namespace std;
double mp[200][200];
vector<int> R[200], P[200], X[200];
double ans = 0;
int n, m, k;
double nw = 0;
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
            if (mp[P[t][i]][P[t][j]] > nw)
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
    while (scanf("%d%d", &n, &k) != EOF)
    {
        vector<double> rd;
        vector<pair<double, double>> a;
        pair<double, double> x;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &x.first, &x.second);
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                mp[i][j] = sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
                rd.push_back(mp[i][j]);
            }
        }
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
            for (int i = 0; i < n; i++)
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
        }
        printf("%.2f\n", rd[b]);
    }
}