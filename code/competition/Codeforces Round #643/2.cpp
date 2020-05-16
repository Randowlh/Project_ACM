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
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int now = 0;
    while (true)
    {
        int f = 0;
        int ma = 0;
        for (int i = now; i < n; i++)
        {

            ma = max(ma, v[i]);
            if (ma == i - now + 1)
            {
                f = 1;
                now = i + 1;
                break;
            }
        }
        if (f)
            cnt++;
        else
        {
            break;
        }
    }
    cout << cnt << endl;
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