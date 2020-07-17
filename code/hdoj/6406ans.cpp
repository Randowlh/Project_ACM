#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
int st[maxn][23];
int logn[maxn];
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
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}
inline int query(int l, int r)
{
    int s = logn[r - l + 1];
    return max(st[l][s], st[r - (1 << s) + 1][s]);
}
void work()
{
}
int main()
{
    logn[1] = 0;
    for (int i = 21; i <= maxn; i++)
        logn[i] = logn[i / 2] + 1;
    int t;
    while (scanf("%d", &t) != EOF)
    {
        for (int i = 0; i < t; i++)
        {
            work();
        }
    }
}