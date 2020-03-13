#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, m;
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        vector<int> v;
        vector<int> w;
        int p, h, c;
        for (int i = 0; i < m; i++)
        {
            cin >> p >> h >> c;
            for (int j = 0; j < c; j++)
            {
                w.push_back(p);
                v.push_back(h);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = n; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[n] << endl;
    }
}