#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct st_table
{
    int date[200100];
    int mx[200100][30];
    inline void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    ll k;
    int n;
    while (true)
    {
        n = read();
        k = read();
        if (n < 0 && k < 0)
            break;
        ll tol = 0;
        for (int i = 1; i <= n; i++)
        {
            b.date[i] = read();
            tol += b.date[i];
        }
        if (tol <= k)
        {
            printf("-1\n");
            continue;
        }
        b.RMQ(n);
        int num = max(1LL, ((k + 1) / b.query(1, n)));
        while (num <= n)
        {
            ll sum = 0;
            for (int i = 0; i < num; i++)
            {
                sum += b.query(i * (n / num) + 1, (i + 1) * (n / num));
                if (sum > k)
                    break;
            }
            if (sum > k)
                break;
            num++;
        }
        if (num > n)
            printf("-1\n");
        else
            printf("%d\n", num);
    }
    return 0;
}