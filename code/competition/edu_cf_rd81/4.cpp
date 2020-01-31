#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll x,y;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
void work()
{
    scanf("%lld%lld", &x, &y);
    ll g = gcd(x, y);
    ll ans = 1;
    y /= g;
    for (ll i = 2; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            ans *= (i - 1);
            y /= i;
            while (y % i == 0)
            {
                ans *= i;
                y /= i;
            }
        }
    }
    if (y != 1)
    {
        ans *= (y - 1);
    }
    printf("%lld\n", ans);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}