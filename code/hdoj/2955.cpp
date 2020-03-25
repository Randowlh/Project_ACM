#include <bits/stdc++.h>
using namespace std;
double dp[110000];
int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        double p, n;
        cin >> p >> n;
        vector<pair<int, double>> v;
        pair<int, double> x;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x.first >> x.second;
            v.push_back(x);
            sum += x.first;
        }
        for (int i = 0; i <= sum; i++)
        {
            dp[i] = -1;
        }
        dp[0] = 1;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = sum; j >= v[i].first; j--)
            {
                if (dp[j - v[i].first] != -1)
                {
                    dp[j] = max(dp[j], dp[j - v[i].first] * (1 - v[i].second));
                }
            }
        }
        int ans = 0;
        for (int i = sum; i >= 0; i--)
        {
            if (1.0 - dp[i] <= p)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}