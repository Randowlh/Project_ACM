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
int fs[4] = {0, 0, 1, 1};
int ha[4] = {0, 1, 0, 1};
void work()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    int now = 0;
    int ans = 0;
    for (int i = tmp.size() - 1; i >= 0;i--){
        if(fs[tmp[i]-'0']){
            ans++;
            continue;
        }else
        if(ha[tmp[i]-'0']){
            if(now){
                ans++;
                now--;
            }else
                now++;
        }else{
            now++;
        }
    }
    cout << ans << endl;
}
signed main()
{
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