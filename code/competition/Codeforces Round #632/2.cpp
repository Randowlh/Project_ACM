#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    int fl1 = 0;
    int fl11 = 0;
    if (a[0] != b[0])
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] < a[i] && fl11 == 0)
        {
            cout << "NO" << endl;
            return;
        }
        if (b[i] > a[i] && fl1 == 0)
        {
            cout << "NO" << endl;
            return;
        }
        if (a[i] == 1)
            fl1 = 1;
        if (a[i] == -1)
            fl11 = 1;
    }
    cout << "YES" << endl;
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