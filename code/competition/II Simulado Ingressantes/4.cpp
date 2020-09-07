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
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    int mx = -llinf;
    int mix = 0;
    int flag = 0;
    for (int i = 0; i < n;i++){
        cin >> tmp;
        if(tmp==mx){
            flag = 1;
        }
        if(tmp>mx){
            mx = tmp;
            mix = i + 1;
            flag = 0;
        }
    }
    if(flag)
        cout << -1 << endl;
    else
        cout << mix << endl;
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