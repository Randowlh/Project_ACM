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
string a = "codeforces";
void work()
{
    int k;
    cin >> k;
    vector<int> ans;
    for (int i = 10; i >= 2; i--)
    {
        if (k == 1)
            break;
        int t = max(2LL, (int)pow(k, 1 / (double)i) - 4);
        cout << t << endl;
        while (k % t != 0)
        {
            t++;
        }
        ans.push_back(t);
        k /= t;
    }
    ans.push_back(k);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < ans[i]; j++)
        {
            cout << a[i];
        }
    }
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}