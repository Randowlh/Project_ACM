#include <bits/stdc++.h>
using namespace std;
long long dp[100000];
int main()
{
    int t;
    cin >> t;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < 10000; i++)
    {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    int tmp;
    for (int q = 0; q < t; q++)
    {
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    return 0;
}