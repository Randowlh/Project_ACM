#include <cstdio>
int dp[100010];
int date[100010];
int left[100010];
int main()
{
    int k;
    scanf("%d", &k);
    int n;
    for (int q = 1; q <= k; q++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &date[i]);
            dp[i] = -9999999;
            left[i] = i;
        }
        dp[0] = date[0];
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] + date[i] < date[i])
            {
                left[i] = i;
                dp[i] = date[i];
            }
            else
            {
                left[i] = left[i - 1];
                dp[i] = dp[i - 1] + date[i];
            }
        }
        int ans = -9999999, ansl, ansr;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                ansl = left[i];
                ansr = i;
            }
        }
        printf("Case %d:\n", q);
        printf("%d %d %d\n", ans, ansl + 1, ansr + 1);
        if (q != k)
        {
            printf("\n");
        }
    }
    return 0;
}