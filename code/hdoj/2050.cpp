#include <bits/stdc++.h>
using namespace std;
long long dp[11000];
int main()
{
    int t;
    cin >> t;
    dp[1] = 2;
    for (int i = 2; i < 10001; i++)
    {
        dp[i] = dp[i - 1] + 4 * (i - 1) + 1;
    }
    int tmp;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    return 0;
}