#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
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
    int n, x;
    int tmp;
    cin >> n >> x;
    vector<int> v;
    int tol = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tol += tmp;
        v.push_back(tmp);
    }
    if (tol % x != 0)
    {
        cout << v.size() << endl;
        return;
    }
    int fr = n - 1;
    int ed = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % x != 0)
        {
            fr = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] % x != 0)
        {
            ed = i;
            break;
        }
    }
    int ans = max(n - 1 - fr, ed);
    if (ans == 0)
        ans = -1;
    cout << ans << endl;
}
signed main()
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