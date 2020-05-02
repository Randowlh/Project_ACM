#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> ans;
void getans(int n)
{
    int now = 1;
    while (now < n)
    {

        n -= now;
        ans.push_back(now);
        now *= 2;
    }
    ans.push_back(n);
}
void work()
{
    ans.clear();
    int n;
    cin >> n;
    getans(n);
    sort(ans.begin(), ans.end());
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] - ans[i - 1] << ' ';
    }
    cout << endl;
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