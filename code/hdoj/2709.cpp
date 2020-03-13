#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1001000];
int main()
{
    int i = 3;
    dp[1] = 1;
    dp[2] = 2;
    while (i < 1000100)
    {
        if (i & 1)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = (dp[i - 2] + dp[i >> 1]) % 1000000000;
        }
        i++;
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}