#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll js(ll x)
{
    return x * (x + 1) / 2;
}
void work()
{
    ll n, m;
    cin >> n >> m;
    ll w = n - m;
    ll ans = js(n);
    ll num = w / (m + 1);
    ll num2 = w % (m + 1);
    ll xg = m + 1 - num2;
    ll dg = num2;
    ans -= js(num) * xg;
    ans -= js(num + 1) * dg;
    cout << ans << endl;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}