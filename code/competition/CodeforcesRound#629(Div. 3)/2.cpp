#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n, m;
    cin >> n >> m;
    int ma = 0;
    for (int i = 2; i <= n; i++)
    {
        if ((i - 1) * i / 2 >= m)
        {
            ma = i;
            break;
        }
    }
    int left = m - (ma - 1) * (ma - 1 - 1) / 2;
    string ans;
    for (int i = 1; i <= n; i++)
    {
        if (i == ma || i == left)
        {
            ans.push_back('b');
        }
        else
        {
            ans.push_back('a');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}