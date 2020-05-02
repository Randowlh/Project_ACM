#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n, k;
    cin >> n >> k;
    int tmp;
    int ma = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    if (s.size() > k)
    {
        cout << -1 << endl;
        return;
    }
    int cnt = 1;
    while (s.size() != k)
    {
        s.insert(cnt);
        cnt++;
    }
    cout << n * s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        for (auto j = s.begin(); j != s.end(); j++)
        {
            cout << *j << ' ';
        }
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