#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node
{
    int a, b;
    bool operator<(node a)
    {
        return b < a.b;
    }
} date[100100];
void work()
{
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> date[i].b;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> date[i].a;
    }
    sort(date, date + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += date[i].a / v * date[i].b;
        date[i + 1].a += date[i].a % v;
    }
    int f = 1;
    if (date[n - 1].a % v == 0)
    {
        f = 0;
    }
    ans += (date[n - 1].a / v + f) * date[n - 1].b;
    cout << ans * 2 << endl;
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