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
int mp[4000][3100];
int dp[4000][3100];
void work()
{
    int n, m, a, b;
    cin>> a >> b >> n >> m;
    int tmp;
    for (int i =1; i <= a;i++)
        for (int j = 1; j <= b;j++){
            cin >> tmp;
            if(tmp){
            mp[i][j]++;
            mp[i][m - b + 1 + j]--;
            mp[n - a + 1 + i][j]--;
            mp[n - a + i + 1][m - b + 1 + j]++;
            
            }
            }
   
            int ma = 0;
    for(int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            dp[i][j] +=mp[i][j]+ dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            ma = max(ma, dp[i][j]);
            }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cout << (int)(dp[i][j]*100.0/ma) << ' ';
        }
        cout << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}