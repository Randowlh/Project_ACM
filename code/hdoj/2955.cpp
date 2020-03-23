#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[100010];
int main()
{
    int t;
    cin >> t;
    double tmp;
    int tt;
    for (int q = 0; q < t; q++)
    {
        int n, m;
        cin >> tmp >> n;
        m = tmp;
        vector<ll> v;
        vector<double> w;
        int tol = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tt;
            tol += tt;
            v.push_back(tt);
            cin >> tmp;
            w.push_back(tmp);
        }
        for (int i = 0; i <= tol; i++)
        {
            dp[i] = -1;
        }
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = tol; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] * (1 - w[i]));
            }
        }
        int ans = 0;
        for (int i = tol; i >= 0; i--)
        {
            if (dp[i] >= 1.0 - m)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }
}