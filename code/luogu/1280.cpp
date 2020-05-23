#include <bits/stdc++.h>
using namespace std;
vector<int> mp[21000];
int dp[21000];
int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        mp[a].push_back(a + b);
    }
    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        if (mp[i].size() == 0)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            dp[i] = 0;
            for (int j = 0; j < mp[i].size(); j++)
            {
                dp[i] = max(dp[i], dp[mp[i][j]]);
            }
        }
    }
    cout << dp[1] << endl;
}