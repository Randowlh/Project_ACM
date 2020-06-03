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
    int n, x;
    cin >> n >> x;
    int tmp;
    int odd = 0;
    int eve = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp & 1)
            eve++;
        else
            odd++;
    }

    if (!eve || x > n)
    {
        out(0);
    }
    else
    {
        if (eve % 2 == 0)
            x -= eve - 1;
        else
            x -= eve;
        if (x < 0)
        {
            x = abs(x) % 2;
        }
        out(odd >= x);
    }
    return;
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