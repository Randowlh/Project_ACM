#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
ll dp[1000];
ll birth[1000];
void work()
{
    int t;
    cin >> t;
    cout << dp[t] << endl;
}
int main()
{
    dp[1] = 1;
    birth[1] = 1;
    birth[2] = 0;
    birth[3] = 4;
    birth[4] = 4;
    birth[5] = 20;
    for (int i = 1; i < 100; i++)
    {
        if (i < 3)
        {
            dp[i] = 1;
        }
        else if (i <= 5)
        {
            dp[i] = dp[i - 1] + dp[i - 2] * 4;
        }
        else
        {
            dp[i] = dp[i - 1] - birth[i - 5] + (birth[i - 2] + birth[i - 3] + birth[i - 4]) * 4;
            birth[i] = (birth[i - 2] + birth[i - 3] + birth[i - 4]) * 4;
        }
    }
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}