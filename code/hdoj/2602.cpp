#include <bits/stdc++.h>
using namespace std;
int dp[11000];
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v, w;
        int tmp;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            w.push_back(tmp);
        }
        for (int i = 0; i < w.size(); i++)
        {
            for (int j = m; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
    }
}