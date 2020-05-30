#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
struct st_table
{
    int date[100100];
    int mx[100100][30];
    void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
int maxsum(int x, int y)
{
    if (y == x + 1)
        return 0;
    int m = (x + y) >> 1;
    int ans = max(maxsum(x, m), maxsum(m, y));
    int l = b.date[m - 1];
    int now = 0;
    for (int i = m - 1; i >= x; i--)
    {
        now += b.date[i];
        if (now > l)
            l = now;
    }
    int r = b.date[m];
    now = 0;
    for (int i = m; i < y; i++)
    {
        now += b.date[i];
        if (now > r)
            r = now;
    }
    return max(ans, max(l, 0LL) + max(0LL, r) - max(0LL, b.query(x, y - 1)));
}

void work()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b.date[i];
    }
    b.RMQ(n);
    cout << maxsum(1, n + 1) << endl;
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