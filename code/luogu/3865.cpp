#include <bits/stdc++.h>
using namespace std;
int st[2001000][23];
int logn[2001000];
int n, m;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
void init(int n)
{
    logn[1] = 0;
    for (int i = 2; i <= n; i++)
        logn[i] = logn[i / 2] + 1;
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}
inline int query(int l, int r)
{
    int s = logn[r - l + 1];
    return max(st[l][s], st[r - (1 << s) + 1][s]);
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = read();
    }
    int a, b;
    init(n);
    for (int i = 0; i < m; i++)
    {
        a = read();
        b = read();
        printf("%d\n", query(a, b));
    }
}