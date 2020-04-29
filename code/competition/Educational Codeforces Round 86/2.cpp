#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    string tmp;
    cin >> tmp;
    int f0 = 0;
    int f1 = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '0')
            f0 = 1;
        if (tmp[i] == '1')
            f1 = 1;
    }
    if ((f1 + f0) == 1)
    {
        cout << tmp << endl;
        return;
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << "01";
    }
    cout << endl;
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