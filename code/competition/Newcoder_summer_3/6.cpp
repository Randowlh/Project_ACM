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
int dp[2510000];
int dis[2510000];
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1;i++){
        dis[i]=v[i+1]-v[i];
    }
    for (int i = 0;i<=n+100;i++){
        dp[i] = llinf;
    }
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int now = llinf;
        if(dp[i+3]!=llinf){
            int tt = 0;
            int flag = 0;
            for (int j = 2; j >=0;j--){
                tt += dis[i + j] * (flag+1);
                if(j==1&&i+3!=n-2){
                    dp[i + 1] = min(dp[i + 1], dp[i+3]+tt);
                }
                flag = flag ^ 1;
            }
            now = min(now, tt+dp[i+3]);
        }
        dp[i] = now;
    }
    // for (int i = 0; i < n;i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < n;i+=2){
        ans += abs(v[i] - v[i + 1]) ;
    }
    cout << dp[0]+ans << endl;
}
signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
 // freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}