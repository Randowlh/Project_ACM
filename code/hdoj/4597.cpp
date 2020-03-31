#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
//#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int dp[21][21][21][21];
vector<int> mp1, mp2;
int n;
int dfs(int x1, int y1, int x2, int y2)
{
    if (dp[x1][y1][x2][y2] != -1)
    {
        return dp[x1][y1][x2][y2];
    }
    if (x1 > y1 || x2 > y2)
        dp[x1][y1][x2][y2] = 0;
    int sum = 0;
    int ans = 0;
    if (x1 <= y1)
        sum += mp1[y1] - mp1[x1 - 1];
    if (x2 <= y2)
        sum += mp2[y2] - mp2[x2 - 1];
    if (x1 <= y1)
    {
        ans = max(ans, sum - dfs(x1 + 1, y1, x2, y2));
        ans = max(ans, sum - dfs(x1, y1 - 1, x2, y2));
    }
    if (x2 <= y2)
    {
        ans = max(ans, sum - dfs(x1, y1, x2 + 1, y2));
        ans = max(ans, sum - dfs(x1, y1, x2, y2 - 1));
    }
    return dp[x1][y1][x2][y2] = ans;
}
void work()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int tmp = 0;
    mp1.clear();
    mp2.clear();
    mp1.push_back(0);
    mp2.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (mp1.empty())
            mp1.push_back(tmp);
        else
            mp1.push_back(tmp + mp1[mp1.size() - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (mp2.empty())
            mp2.push_back(tmp);
        else
            mp2.push_back(tmp + mp2[mp2.size() - 1]);
    }
    cout << dfs(1, n, 1, n) << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}