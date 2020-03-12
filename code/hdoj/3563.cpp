#include <bits/stdc++.h>
using namespace std;
int dp[10000];
int main()
{
    int t;
    cin >> t;
    dp[1] = 3;
    dp[2] = 7;
    for (int i = 3; i < 1000; i++)
    {
        dp[i] = dp[i - 1] * 2 + dp[i - 2];
    }
    int tmp;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    return 0;
}