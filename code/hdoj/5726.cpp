#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
struct st_table
{
    int date[200100];
    int mx[200100][35];
    inline void RMQ(int num)
    {
        for (register int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (register int j = 1; j < 20; ++j)
            for (register int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = gcd(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return gcd(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
int cnt = 1;
inline int read()
{
    int x = 0, f = 1;
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
map<int, int> M;
void work()
{
    M.clear();
    printf("Case #%lld:\n", cnt);
    cnt++;
    int n;
    n = read();
    for (register int i = 1; i <= n; i++)
    {
        b.date[i] = read();
    }
    b.RMQ(n);
    int m;
    m = read();
    for (register int i = 0; i < m; i++)
    {
        int ans1 = 0;
        int ans2 = 0;
        int l, r;
        l = read();
        r = read();
        ans1 = b.query(l, r);
        printf("%lld ", ans1);
        if (M[ans1] != 0)
            printf("%lld\n", M[ans1]);
        else
        {
            for (register int i = 1; i <= n; i++)
            {
                if (gcd(b.date[i], ans1) != ans1)
                    continue;
                int be = i;
                int ed = n;
                while (be <= ed)
                {
                    int mid = (be + ed) >> 1;
                    if (b.query(i, mid) < ans1)
                        ed = mid - 1;
                    else
                        be = mid + 1;
                }
                int lr = be;
                be = i;
                ed = n;
                while (be <= ed)
                {
                    int mid = (be + ed) >> 1;
                    if (b.query(i, mid) <= ans1)
                        ed = mid - 1;
                    else
                        be = mid + 1;
                }
                ans2 += lr - be;
            }
            M[ans1] = ans2;
            printf("%lld\n", ans2);
        }
    }
    return;
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    while (t--)
    {
        work();
    }
    return 0;
}