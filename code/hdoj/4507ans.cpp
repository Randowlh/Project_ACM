#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = 1e9 + 7;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node
{
    int cnt;
    int sum;
    int sumsqr;
    node(int a = 0, int b = 0, int c = 0) : cnt(a), sum(b), sumsqr(c) {}
};
node dp[20][10][10][2];
int disg[20];
node dfs(int pos, int md, int md2, bool staus, bool flag)
{
    if (pos == 0)
    {
        if (md % 7 == 0 || md2 % 7 == 0 || staus == 1)
            return node(0, 0, 0);
        else
            return node(1, 0, 0);
    }
    if (!flag && dp[pos][md][md2][staus].cnt != -1)
        return dp[pos][md][md2][staus];
    int num = flag ? disg[pos] : 9;
    node ans(0, 0, 0);
    for (int i = 0; i <= num; i++)
    {
        node now = dfs(pos - 1, (md + i) % 7, (md2 * 10 + i) % 7, staus || i == 7, flag && i == disg[pos]);
        if (now.cnt >= 1)
        {
            int cheng = 1;
            for (int j = 1; j < pos; j++)
                cheng = cheng * 10 % mod;
            cheng *= i;
            cheng %= mod;
            ans.cnt += now.cnt;
            ans.cnt %= mod;
            ans.sum += now.sum + cheng * now.cnt % mod;
            ans.sum %= mod;
            ans.sumsqr += (((cheng * cheng) % mod) * now.cnt) % mod + ((2 * cheng) % mod) * now.sum % mod + now.sumsqr % mod;
            ans.sumsqr %= mod;
        }
    }
    if (!flag)
        dp[pos][md][md2][staus] = ans;
    return ans;
}
int work(int x)
{
    // if (x <= 0)
    //     return 0;
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    cnt--;
    return dfs(cnt, 0, 0, 0, 1).sumsqr;
}
signed main()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
            {
                dp[i][j][k][1] = *(new node(-1, 0, 0));
                dp[i][j][k][0] = *(new node(-1, 0, 0));
            }
    //freopen("in.txt", "r", stdin);
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            int l, r;
            cin >> l >> r;
            cout << (work(r) - work(l - 1) + mod) % mod << endl;
        }
    return 0;
}