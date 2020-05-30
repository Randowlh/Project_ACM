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
    double h, c, t;
    cin >> h >> c >> t;
    if (t <= (h + c) / 2)
    {
        cout << 2 << endl;
        return;
    }
    double dis = t - (h + c) / 2;
    int now = 1;
    double chu = h - (h + c) / 2;
    int b = 0;
    int e = inf;
    while (e > b)
    {
        double mid = (e + b) / 2;
        if (dis > chu / (mid * 2 + 1))
        {
            e = mid;
        }
        else
            b = mid + 1;
    }
    now = b * 2 + 1;
    if (now == 1)
        cout << now << endl;
    else if (abs(dis - chu / now) < abs(dis - chu / (now - 2)))
    {
        cout << now << endl;
    }
    else
        cout << now - 2 << endl;
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