#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int mp[200100];
void work()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n >= 2)
    {
        int b = 0;
        int e = 100000;
        while (b + 1 < e)
        {
            int mid = (b + e) >> 1;
            if (mp[mid] <= n)
                b = mid;
            else
                e = mid;
        }
        // cout << mp[b] << endl;
        n -= mp[b];
        cnt++;
    }
    cout << cnt << endl;
}
signed main()
{
    int now = 5;
    mp[0] = 2;
    for (int i = 1; i <= 100000; i++)
    {
        mp[i] = mp[i - 1] + now;
        now += 3;
    }
    //cout << mp[100000] << endl;
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