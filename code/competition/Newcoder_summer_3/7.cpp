#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353); 
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int dp[251000];
int arr[251000];
void work()
{
    for (int i = 0; i < n;i++[

    ])
        int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 0; i <= n;i++){
        dp[i] = llinf;
    }
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        if(i-3>0&&dp[i-4]!=llinf){
            dp[i] = min(dp[i - 4] + 2 * abs(arr[i - 3] - arr[i]),dp[i]);
        }
        if(i-5>0&&dp[i-6]!=llinf){
            dp[i] = min(dp[i - 6] + 2 * abs(arr[i - 5] - arr[i]), dp[i]);
        }
    }
    cout << dp[n] << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}''