#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
int mp[510][510];
int ans = 0;
int pr[510];
int book[510];
bool dfs(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (pr[i] == -1 || dfs(pr[i]))
            {
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 0; i < n; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    return;
}
void work()
{
    int n, m;
    while (scanf("%lld %lld", &n, &m) != EOF)
    {
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