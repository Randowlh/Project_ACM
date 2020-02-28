#include <bits/stdc++.h>
using namespace std;
vector<int> date;
int m; //价格表的元素数量
int prize[11000];
int BOTTOM_UP_CUT_ROD(int n)
{
    int dp[101000];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = -0x7FFFFFFF;
        for (int j = 0; j < m; j++)
        {
            if (i >= j)
            {
                now = max(now, dp[i - j] + prize[j]);
            }
        }
        dp[i] = now;
    }
    return dp[n];
}