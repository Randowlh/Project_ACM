#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int dp[20][4][20];
int disg[200];
int dfs(int pos, int staus, int flag, int mod)
{
    if (pos == 0)
        return staus == 2 && mod == 0;
    if (flag && dp[pos][staus][mod] != -1)
        return dp[pos][staus][mod];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (staus == 2 || (staus == 1 && i == 3))
            ans += dfs(pos - 1, 2, flag || i < num, (mod * 10 + i) % 13);
        else if (i == 1)
            ans += dfs(pos - 1, 1, flag || i < num, (mod * 10 + i) % 13);
        else
            ans += dfs(pos - 1, 0, flag || i < num, (mod * 10 + i) % 13);
    }
    if (flag)
        dp[pos][staus][mod] = ans;
    return ans;
}
void work()
{
    int n;
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        memset(disg, 0, sizeof(disg));

        int cnt = 1;
        while (n)
        {
            disg[cnt] = n % 10;
            n /= 10;
            cnt++;
        }
        cnt--;
        cout << dfs(cnt, 0, 0, 0) << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}