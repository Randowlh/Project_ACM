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
vector<int> primes;
const int maxn = 10000000;
bool is_prime[100000100];
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i <n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int ans=0;
    for (int i = 0; i < n;i++){
        ans += abs(v[i] - v[(i + 1) % n]);
    }
    cout << ans << endl;
}
signed main()
{
    // euler();
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
}