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
    int x, m, n;
    cin >> x >> n >> m;
    for (int i = 0; i < n; i++)
    {
        if (x > 20)
        {
            x = x / 2;
            x += 10;
        }
        else
            break;
    }
    x -= m * 10;
    if (x <= 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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