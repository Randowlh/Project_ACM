#include <bits/stdc++.h>
#define ll long long
#define int ll
const ll tt = 1e9 + 7;
int _, n, a[25];
ll p[25];
struct record
{
    ll cnt, sum1, sum2;
    void init() { cnt = -1, sum1 = 0, sum2 = 0; }
} f[25][10][10];
record dfs(int x, int y, int z, int limit)
{
    int i, r;
    ll w;
    record k, res;
    if (!x)
        return (record){y && z, 0, 0};
    if (f[x][y][z].cnt >= 0 && !limit)
        return f[x][y][z];
    r = limit ? a[x] : 9;
    res.cnt = res.sum1 = res.sum2 = 0;
    for (i = 0; i <= r; i++)
        if (i ^ 7)
        {
            k = dfs(x - 1, (y + i) % 7, (10 * z + i) % 7, limit && i == r);
            if (!k.cnt)
                continue;
            res.cnt += k.cnt;
            res.cnt %= tt;
            //(res.cnt += k.cnt) %= tt;
            w = i * p[x - 1] % tt;
            if (x == 2)
                printf("%d %d %d %d %d %d\n", x, y, z, i, k.cnt, w);
            res.sum1 += k.cnt * w % tt + k.sum1 % tt;
            res.sum1 %= tt;
            res.sum2 += k.cnt * w % tt * w % tt + k.sum1 * 2 % tt * w % tt + k.sum2;
            res.sum2 %= tt;
        }
    printf("%d %d %d %lld\n", x, y, z, res.sum2);
    if (!limit)
        f[x][y][z] = res;
    return res;
}
ll solve(ll x)
{
    n = a[0] = 0;
    while (x)
    {
        a[++n] = x % 10;
        x /= 10;
    }
    return dfs(n, 0, 0, 1).sum2;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    int i, j, k;
    ll x, y;
    p[0] = 1;
    for (i = 1; i <= 20; i++)
        p[i] = p[i - 1] * 10 % tt;
    for (i = 0; i <= 20; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                f[i][j][k].init();
    for (scanf("%d", &_); _; _--)
    {
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", (solve(y) - solve(x - 1) + tt) % tt);
    }
    return 0;
}
