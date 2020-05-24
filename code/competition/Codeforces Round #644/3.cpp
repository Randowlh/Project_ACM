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
    int odd = 0;
    int eve = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp & 1)
            eve++;
        else
            odd++;
        v.push_back(tmp);
    }
    if (eve % 2 == 0)
    {
        out(1);
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] == 1)
        {
            out(1);
            return;
        }
    }
    out(0);
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