#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int w[2011];
int dp[2011][2011];
int calc(int i, int j)
{
    return (w[i] - w[j]) * (w[i] - w[j]);
}
int main()
{
    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &w[i]);
        }
        sort(w + 1, w + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
                dp[i][i / 2] = calc(i - 1, i) + dp[i - 2][(i - 2) / 2];
        }
        for (int i = 1; i <= k; i++)
            for (int j = 2; j <= n; j++)
            {
                if (j > i * 2)
                    dp[j][i] = min(dp[j - 1][i], dp[j - 2][i - 1] + calc(j, j - 1));
            }
        cout << dp[n][k] << endl;
    }
    return 0;
}