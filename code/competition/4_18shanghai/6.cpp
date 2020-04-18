#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n;
    cin >> n;
    string ans = "11";
    if (n == 1)
    {
        cout << 1 << endl;
        cout << ans << endl;
        return;
    }
    if (n == 2)
    {
        cout << 2 << endl;
        cout << "11" << endl;
        cout << "000" << endl;
        return;
    }
    if (n == 3)
    {
        cout << 3 << endl;
        cout << 11 << endl;
        cout << 101 << endl;
        cout << "000" << endl;
        return;
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << ans << endl;
        ans.pop_back();
        ans.push_back('0');
        ans.push_back('1');
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