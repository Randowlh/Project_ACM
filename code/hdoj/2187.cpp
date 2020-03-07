#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int q = 0; q < t; q++)
    {
        int n;
        double m;
        scanf("%lf%d", &m, &n);
        double ans = 0;
        vector<pair<double, double>> v;
        pair<double, double> x;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &x.first, &x.second);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (m >= v[i].second * v[i].first)
            {
                ans += v[i].second;
                m -= v[i].second * v[i].first;
            }
            else
            {
                ans += m / v[i].first;
                break;
            }
        }
        printf("%.2f\n", ans);
    }
}