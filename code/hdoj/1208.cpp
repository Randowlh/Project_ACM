#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int b[][2] = {{1, 0}, {0, 1}};
int n;
int dp[100][100];
char mp[100][100];
bool ck(int x, int y)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= n)
        return false;
    return true;
}
int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = 0;
    if (mp[x][y] == 0)
    {
        dp[x][y] = 0;
        return 0;
    }
    for (int i = 0; i < 2; i++)
    {
        if (ck(x + mp[x][y] * b[i][0], y + mp[x][y] * b[i][1]))
        {
            ans += dfs(x + mp[x][y] * b[i][0], y + mp[x][y] * b[i][1]);
        }
    }
    dp[x][y] = ans;
    return ans;
}
void work()
{
    while (cin >> n && n >= 0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> mp[i][j];
                mp[i][j] -= '0';
                dp[i][j] = -1;
            }
        dp[n - 1][n - 1] = 1;
        cout << dfs(0, 0) << endl;
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