#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
string mp[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
inline int dis(string a, string b)
{
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        if (a[i] == b[i])
            continue;
        if (a[i] == '0' && b[i] == '1')
            return -1;
        if (a[i] == '1' && b[i] == '0')
            ans++;
    }
    return ans;
}
string dp[2][2110];
void work()
{
    int n, k;
    cin >> n >> k;
    string tmp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[0][0] = "0";
    for (int kk = 0; kk < n; kk++)
    {
        int i = 0;
        for (int ks = 0; ks < 10; ks++)
        {
            int t = dis(mp[ks], v[kk]);
            if (t == -1)
                continue;
            for (int j = 0; j <= k - t; j++)
            {
                if (!dp[i][j].empty())
                {
                    dp[i][j].push_back(ks + '0');
                    if (dp[i + 1][j + t].empty())
                    {
                        dp[i + 1][j + t] = dp[i][j];
                    }
                    else if (dp[i + 1][j + t] < dp[i][j])
                    {
                        dp[i + 1][j + t] = dp[i][j];
                    }
                    dp[i][j].pop_back();
                }
            }
        }
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = move(dp[i + 1][j]);
            dp[i + 1][j].clear();
        }
    }
    if (dp[0][k].empty())
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (int i = 1; i < dp[0][k].size(); i++)
            cout << dp[0][k][i];
        cout << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}