#include <bits/stdc++.h>
using namespace std;
double dp[100], chu[100];
int main()
{
    dp[1] = 0;
    dp[2] = 1;
    for (long long i = 3; i <= 20; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    chu[1] = 1;
    chu[2] = 2;
    for (long long i = 3; i <= 30; i++)
    {
        chu[i] = chu[i - 1] * i;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        printf("%.2f%%\n", (double)dp[n] * 100.0 / (double)chu[n]);
    }
    return 0;
}