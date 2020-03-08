#include <bits/stdc++.h>
using namespace std;
int ma[1100000], c[110000];
int dp[110000];
int m, n;
void getnext()
{
    int i = 0, j = -1;
    dp[0] = -1;
    while (i < m)
    {
        if (j == -1 || c[i] == c[j])
        {
            i++;
            j++;
            dp[i] = j;
        }
        else
            j = dp[j];
    }
}
int KMP(int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || ma[i] == c[j])
        {
            i++;
            j++;
        }
        else
            j = dp[j];
    }
    if (j == m)
        return i - j + 1;
    else
        return -1;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int q = 0; q < t; q++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &ma[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &c[i]);
        }
        getnext();
        printf("%d\n", KMP(n, m));
    }
    return 0;
}