#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    ll n, g, b;
    cin >> n >> g >> b;
    ll tn = n;
    if (n % 2 == 0)
    {
        n /= 2;
    }
    else
    {
        n++;
        n /= 2;
    }
    ll t = g + b;
    ll ans1;
    if (n % g != 0)
    {
        ans1 = n / g * t;
        ans1 += n % g;
    }
    else
    {
        ans1 = n / g * t;
        ans1 -= b;
    }
    ll ans2 = tn;
    cout << max(ans1, ans2) << endl;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}