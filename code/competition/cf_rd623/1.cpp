#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll ans = 0;
    ans = max(x * m, ans);
    ans = max((n - x - 1) * m, ans);
    ans = max(y * n, ans);
    ans = max((m - y - 1) * n, ans);
    cout << ans << endl;
}
int main()
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