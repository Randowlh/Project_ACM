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
int dis[251000];
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
    int tail = 0;
    for (int i = 0; i < n - 1;i++){
        dis[tail] = v[i + 1] - v[i];
        tail++;
    }
    for (int i = 0;i<=tail+100;i++){
        dp[i] = llinf;
    }
    dp[tail- 1] = dis[tail - 1];
    for(int i=tail-2;i>=0;i--){
        int now = llinf;
        if(dp[i+3]!=llinf){
            int tt = 0;
            int flag = 0;
            for (int j = 2; j >=0;j--){
                tt += dis[i + j] * (flag+1);
                if(j==1){
                    dp[i + 1] = min(dp[i + 1], dp[i+3]+tt);
                }
                flag = flag ^ 1;
            }
            now = min(now, tt+dp[i+3]);
        }
        dp[i] = now;
    }
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
  freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}