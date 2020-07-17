#include <bits/stdc++.h>
using namespace std;
const int mod = 2012;
int dp[1005][1005];
char str[1005];
int sum[1005];
inline void add(int &x, int y)
{
    x += y;
    if (x >= mod)
        x %= mod;
}
int main()
{
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (str[i] == '(' ? 1 : -1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[i - 1][j] == 0)
                continue;
            if (str[i] == '(')
            {
                add(dp[i][j + 1], dp[i - 1][j]);
                add(dp[i][j], dp[i - 1][j]);
            }
            else
            {
                if (j - 1 >= 0)
                    add(dp[i][j - 1], dp[i - 1][j]);
                if (sum[i] - j >= 0)
                    add(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}