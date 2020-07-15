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
node dp[20][10][10][10];
int disg[20];
ll q(int x)
{
    ll tmp = 1;
    for (int i = 1; i <= x; i++)
    {
        tmp *= 10;
        tmp %= mod;
    }
    return tmp;
}
node dfs(int pos, int sta, int sa, int sb, bool limit)
{
    if (pos == -1)
    {
        node tmp;
        if (sta == 1 || sa % 7 == 0 || sb % 7 == 0)
        {
            tmp.cnt = 0;
            tmp.sum = 0;
            tmp.sumsqr = 0;
            return tmp;
        }
        else
        {
            tmp.cnt = 1;
            tmp.sum = 0;
            tmp.sumsqr = 0;
            return tmp;
        }
    }
    if (!limit && dp[pos][sta][sa][sb].cnt != -1)
        return dp[pos][sta][sa][sb];
    int up = limit ? disg[pos] : 9;
    node tmp;
    tmp.cnt = tmp.sum = tmp.sumsqr = 0;
    for (int i = 0; i <= up; i++)
    {
        node ttp = dfs(pos - 1, sta || i == 7, (sa + i) % 7, (sb * 10 + i) % 7, limit && i == disg[pos]);

        ll x = i * q(pos);
        x %= mod;

        tmp.cnt += ttp.cnt;
        tmp.cnt %= mod;

        if (pos == 0)
            tmp.sum += i;
        else
            tmp.sum += ttp.sum + x * ttp.cnt % mod;
        tmp.sum %= mod;

        tmp.sumsqr += (((x * x) % mod) * ttp.cnt) % mod + ((2 * x) % mod) * ttp.sum % mod + ttp.sumsqr % mod;
        tmp.sumsqr %= mod;
    }
}
if (!limit)
    dp[pos][sta][sa][sb] = tmp;
return tmp;
}
int work(int x)
{
    // if (x <= 0)
    //     return 0;
    int cnt = 0;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    return dfs(cnt - 1, 0, 0, 0, true).sumsqr;
}
signed main()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int q = 0; q < 10; q++)
                {
                    dp[i][j][k][q] = *(new node(-1, 0, 0));
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