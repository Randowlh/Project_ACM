#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int unsigned long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[200][100];
int disg[200];
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int dfs(int pos, int staus, int flag)
{
    if (pos == 0)
        return staus == 2;
    if (flag && dp[pos][staus] != -1)
    {
        return dp[pos][staus];
    }
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (staus == 2 || (staus == 1 && i == 9))
            ans += dfs(pos - 1, 2, flag || i < num);
        else if (i == 4)
            ans += dfs(pos - 1, 1, flag || i < num);
        else
            ans += dfs(pos - 1, 0, flag || i < num);
    }
    if (flag)
        dp[pos][staus] = ans;
    return ans;
}
void work()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    memset(disg, 0, sizeof(disg));
    int cnt = 1;
    int tn = n;
    while (tn)
    {
        disg[cnt] = tn % 10;
        tn /= 10;
        cnt++;
    }
    cnt--;
    cout << dfs(cnt, 0, 0) << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}