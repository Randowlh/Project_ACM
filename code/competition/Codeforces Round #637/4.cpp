#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
string mp[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
inline int dis(string &a, string &b)
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
int dp[2110][2110];
int pr[2100][2100];
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
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int ks = 0; ks < 10; ks++)
        {
            int t = dis(mp[ks], v[n - i - 1]);
            // cout << i << ' ' << t << ' ' << ks << endl;
            if (t == -1)
                continue;
            for (int j = 0; j <= k; j++)
            {
                if (dp[i][j] != -1)
                {
                    if (dp[i + 1][j + t] == -1)
                    {
                        dp[i + 1][j + t] = ks;
                        pr[i + 1][j + t] = j;
                    }
                    else if (dp[i + 1][j + t] < ks)
                    {
                        dp[i + 1][j + t] = ks;
                        pr[i + 1][j + t] = j;
                    }
                    else if (dp[i + 1][j + t] == ks && pr[i + 1][j + t] < j)
                    {
                        dp[i + 1][j + t] = ks;
                        pr[i + 1][j + t] = j;
                    }
                }
            }
        }
    }
    if (dp[n][k] == -1)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        vector<int> ans;
        ans.push_back(dp[n][k]);
        int now = pr[n][k];
        for (int i = n - 1; i > 0; i--)
        {
            ans.push_back(dp[i][now]);
            now = pr[i][now];
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}