#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int aa, bb;
    for (int i = 0; i < n; i++)
    {
        cin >> aa >> bb;
        a.push_back(aa);
        b.push_back(bb);
    }
    a.push_back(a[0]);
    int ans = 0;
    int mi = 9223372036854775807;
    for (int i = 1; i <= n; i++)
    {
        mi = min(mi, a[i] - max((int)0, a[i] - b[i - 1]));
        ans += max((int)0, a[i] - b[i - 1]);
    }
    cout << ans + mi << endl;
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