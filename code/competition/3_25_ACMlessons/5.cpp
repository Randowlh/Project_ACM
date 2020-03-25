#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
int fast_pow(int x, int y)
{
    int ans = 1;
    int tmp = x;
    while (y != 0)
    {
        if (y & 1)
        {
            ans *= tmp;
        }
        tmp *= tmp;
        y >>= 1;
    }
    return ans;
}
void work()
{
    ll n;
    while (cin >> n)
    {
        if (n == 0)
            return;
        vector<int> v;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int cnt = 0;
                while (n % i == 0)
                {
                    cnt++;
                    n /= i;
                }
                v.push_back(cnt);
            }
        }
        if (n != 1)
        {
            v.push_back(1);
        }
        ll ans = 1;
        for (int i = 0; i < v.size(); i++)
        {
            ans *= v[i] + 1;
        }
        cout << ans << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}