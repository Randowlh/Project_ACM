#include <bits/stdc++.h>
using namespace std;
int n;
int dp[510000];
int arr[510000];
int main()
{
    int cnt = 0;
    // freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) == 1)
    {
        cnt++;
        printf("Case %d:\n", cnt);
        int p, r;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p, &r);
            arr[p] = r;
        }
        int len = 0;
        dp[0] = -99;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] > dp[len])
            {
                len++;
                dp[len] = arr[i];
                continue;
            }
            else
            {
                int *t = lower_bound(dp + 1, dp + len, arr[i]);
                if (*t > arr[i])
                {
                    *t = arr[i];
                }
            }
        }
        if (len == 1)
            printf("My king, at most %d road can be built.\n\n", len);
        else
            printf("My king, at most %d roads can be built.\n\n", len);
    }
}