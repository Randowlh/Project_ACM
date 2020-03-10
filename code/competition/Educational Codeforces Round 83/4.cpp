#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = 998244353;
int dp[210000];
void work()
{
    int n, m;
    cin >> n >> m;
    if (m < n - 1)
    {
        cout << 0 << endl;
        return;
    }
    dp[n - 1] =
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}