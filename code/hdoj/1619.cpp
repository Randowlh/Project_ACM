#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[1100][1100];
int mp[1100][1100];
int lj[1100][1100];
int n, m;
int b[][2] = {{-1, 1}, {0, 1}, {1, 1}};
int b1[][2] = {{0, 1}, {1, 1}, {-1, 0}};
int b2[][2] = {{1, 1}, {-1, 1}, {0, 0}};
int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = llinf - 99;
    if (x == 0)
        for (int i = 0; i < 3; i++)
        {
            int t = dfs((x + b1[i][0] + n) % n, y + 1);
            if (t < ans)
            {
                ans = t;
                lj[x][y] = (x + b1[i][0] + n) % n;
            }
        }
    else if (x == n - 1)
        for (int i = 0; i < 3; i++)
        {
            int t = dfs((x + b2[i][0] + n) % n, y + 1);
            if (t < ans)
            {
                ans = t;
                lj[x][y] = (x + b2[i][0] + n) % n;
            }
        }
    else
        for (int i = 0; i < 3; i++)
        {
            int t = dfs((x + b[i][0] + n) % n, y + 1);
            if (t < ans)
            {
                ans = t;
                lj[x][y] = (x + b[i][0] + n) % n;
            }
        }
    dp[x][y] = ans + mp[x][y];
    return dp[x][y];
}
void work()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                dp[i][j] = -1;
                lj[i][j] = 0;
            }
        for (int i = 0; i < n; i++)
            dp[i][m - 1] = mp[i][m - 1];
        vector<int> ans;
        int now = 0;
        int a = inf;
        for (int i = 0; i < n; i++)
        {
            int t = dfs(i, 0);
            if (a > t)
            {
                a = t;
                now = i;
            }
        }
        for (int i = 0; i < m; i++)
        {
            ans.push_back(now + 1);
            now = lj[now][i];
        }
        for (int i = 0; i < m - 1; i++)
            cout << ans[i] << ' ';
        cout << ans[m - 1] << endl;
        cout << a << endl;
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