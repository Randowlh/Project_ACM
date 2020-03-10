#include <bits/stdc++.h>
using namespace std;
int pr[11000];
int dp[11000];
int date[11000];
int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &date[i]);
        }
        dp[0] = date[0];
        pr[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] < 0)
            {
                dp[i] = date[i];
                pr[i] = i;
            }
            else
            {
                dp[i] = date[i] + dp[i - 1];
                pr[i] = pr[i - 1];
            }
        }
        int ma = -99999;
        int mix = -1;
        for (int i = 0; i < n; i++)
        {
            if (ma < dp[i])
            {
                ma = dp[i];
                mix = i;
            }
        }
        if (ma < 0)
        {
            printf("%d %d %d\n", 0, date[0], date[n - 1]);
        }
        else
            printf("%d %d %d\n", ma, date[pr[mix]], date[mix]);
    }
    return 0;
}