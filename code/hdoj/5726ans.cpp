#include <bits/stdc++.h>
using namespace std;
int date[200100];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct st_table
{
    //int date[200100];
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
int cnt = 0;
unordered_map<int, long long> M;
void work()
{
    cnt++;
    printf("Case #%d:\n", cnt);
    M.clear();
    int n;
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
    {
        scanf("%d", &date[i]);
    }
    b.RMQ(n);
    int q;
    for (int i = 1; i <= n; ++i)
    {
        int g = date[i];
        int j = i;
        while (j <= n)
        {
            int r = n, l = j;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (b.query(i, mid) == g)
                    l = mid;
                else
                    r = mid - 1;
            }
            M[g] += (l - j + 1);
            j = l + 1;
            g = b.query(i, j);
        }
    }
    scanf("%d", &q);
    int l, r;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d %lld\n", b.query(l, r), M[b.query(l, r)]);
    }
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
        work();
    return 0;
}
