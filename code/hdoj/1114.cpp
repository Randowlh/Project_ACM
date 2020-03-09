#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
ll dp[110000];
int w[11000];
int v[11000];
void work()
{
    int pig, tol;
    cin >> pig >> tol;
    tol -= pig;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i <= tol; i++)
    {
        dp[i] = 9999999;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = w[i]; j <= tol; j++)
        {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    if (dp[tol] == 9999999)
    {
        cout << "This is impossible." << endl;
    }
    else
        cout << "The minimum amount of money in the piggy-bank is " << dp[tol] << "." << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}