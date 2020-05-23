#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
struct st_table
{
    int date[100100];
    int mx[100100][40];
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
int dp[100100];
int dp2[100100];
inline int getpos(int _l, int _r, int v)
{
    int l, r, mid;
    l = _l;
    r = _r;
    if (l > r)
        return -1;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (b.query(l, mid) <= v)
            l = mid + 1;
        else
            r = mid;
    }
    if (b.query(l, l) <= v)
        return -1;
    return l;
}
void work()
{
    int n, q;
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b.date[i]);
    dp[n] = 1;
    for (int i = n - 1; i; i--)
    {
        int pos = getpos(i + 1, n, b.date[i]);
        if (pos != -1)
            dp[i] = dp[pos] + 1;
        else
            dp[i] = 1;
    }
    dp2[0] = 0;
    for (int i = 1; i <= n; i++)
        dp2[i] = max(dp2[i - 1], b.date[i]);
    b.RMQ(n);
    int c, d;
    for (int i = 0; i < q; i++)
    {
        scanf("%lld%lld", &c, &d);
        int mx = c - 1 >= 1 ? b.query(1, c - 1) : -1;
        // cout << mx << endl;
        printf("%lld\n", (int)(mx < d ? 1 : 0) + dp2[c - 1] + dp[min(n, getpos(c + 1, n, max(mx, d)))]);
        //cout << "second" << dp[getpos(c + 1, n, max(mx, d))] << endl;
    }
    return;
}
signed main()
{
    //  freopen("in.txt", "r", stdin);
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        work();
    }
    return 0;
}
