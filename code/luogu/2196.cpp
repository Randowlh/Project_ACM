#include <bits/stdc++.h>
using namespace std;
int n;
int mp[30][30];
int dp[30];
int nex[30];
int main()
{
    vector<int> v;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        int ans = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (mp[i][j] && ans < dp[i + j + 1])
            {
                ans = dp[i + j + 1];
                nex[i] = i + j + 1;
            }
        }
        dp[i] = ans + v[i - 1];
    }
    int aa = 0;
    int mix = 0;
    for (int i = 1; i <= n; i++)
    {
        if (aa < dp[i])
        {
            aa = dp[i];
            mix = i;
        }
    }
    vector<int> ans;
    ans.push_back(mix);
    while (nex[mix])
    {
        mix = nex[mix];
        ans.push_back(mix);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << aa << endl;
}