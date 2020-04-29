#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int l, r;
int lcms;
int ck(int x)
{
    return r / x - (l - 1) / x + 1;
}
void work()
{
    int a, b, q;
    cin >> a >> b >> q;
    if (a > b)
        swap(a, b);
    lcms = a * b / gcd(a, b);
    int add = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        int ll = (l - 1) / lcms * lcms;
        int rr = r / lcms * lcms + b - 1;
        add = max(r, rr) - r;
        add += b - (max(ll + b - 1, l - 1) - l + 1);
        int ans = r - l + 1 - ck(lcms) * b + add;
        //cout << "ck(s)" << ck(lcms) << " " << max(r, rr) - r << " " << b - min(r - l + 1, (max(ll + b - 1, l - 1) - l + 1)) << " " << add << endl;
        cout << ans << ' ';
    }
    cout << endl;
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