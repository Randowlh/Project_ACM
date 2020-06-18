#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
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
    int n;
    cin >> n;
    int tmp;
    vector<int> v, tv;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    tv = v;
    sort(tv.begin(), tv.end());
    int now = 0;
    int ma = 0;
    while (now < tv.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == tv[now])
            {
                cnt++;
                now++;
            }
        }
        ma = max(ma, cnt);
    }
    cout << n - ma << endl;
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
