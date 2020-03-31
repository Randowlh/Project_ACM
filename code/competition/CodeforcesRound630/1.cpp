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
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x < x1 || x > x2 || y < y1 || y > y2)
    {
        cout << "No" << endl;
        return;
    }
    if (y1 == y2 && (c || d))
    {
        cout << "No" << endl;
        return;
    }
    if (x1 == x2 && (a || b))
    {
        cout << "No" << endl;
        return;
    }
    int l = x - x1;
    int r = x2 - x;
    int dd = y - y1;
    int u = y2 - y;
    if (a - b > l || b - a > r || c - d > dd || d - c > u)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
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