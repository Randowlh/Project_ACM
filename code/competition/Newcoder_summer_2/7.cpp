#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
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
int n, m;
int st[1010][1010][13][13];
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline void init()
{
    for (int i = 0; i <= log2(n); i++)
        for (int j = 0; j <= log2(m); j++)
        {
            if (i == 0 && j == 0)
                continue;
            for (int x = 1; x <= n; x++)
                for (int y = 1; y <= m; y++)
                {
                    int rx = x + (1 << i) - 1;
                    int ry = y + (1 << j) - 1;
                    if (rx > n || ry > m)
                        continue;
                    if (i == 0)
                    {
                        st[x][y][i][j] = max(st[x][y][i][j - 1], st[x][y + (1 << (j - 1))][i][j - 1]);
                    }
                    else
                    {
                        st[x][y][i][j] = max(st[x][y][i - 1][j], st[x + (1 << (i - 1))][y][i - 1][j]);
                    }
                }
        }
}
int query_max(int x1, int y1, int x2, int y2)
{
    int k1 = log2(x2 - x1 + 1);
    int k2 = log2(y2 - y1 + 1);
    return max(
        max(
            st[x1][y1][k1][k2],
            st[x2 - (1 << k1) + 1][y1][k1][k2]),
        max(
            st[x1][y2 - (1 << k2) + 1][k1][k2],
            st[x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2]));
}
void work()
{
    int k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                st[i][j][0][0] = lcm(i, j);
            }
        }
        init();
        long long ans = 0;
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= m; j++)
            {
                ans += query_max(i - k + 1, j - k + 1, i, j);
            }
        }
        printf("%lld\n", ans);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}