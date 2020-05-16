#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    int n, k;
    cin >> n >> k;
    if (k / n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> ans;
    int tn = k;
    for (int i = 0; i < n - 1; i++)
    {
        ans.push_back(k / n);
        tn -= k / n;
    }
    ans.push_back(tn);
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << 1 << endl;
}
signed main()
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