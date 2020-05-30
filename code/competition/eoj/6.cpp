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
int dij[100];
vector<int> ans;
void out()
{
    for (int i = 0; i < 10; i++)
    {
        while (dij[i])
        {
            ans.push_back(i);
            dij[i]--;
        }
    }
    if (ans[ans.size() - 1] == 0)
    {
        int f = 0;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (f)
            {
                cout << ans[i];
            }
            if (ans[i] != 0)
            {
                f = 1;
                cout << ans[i];
            }
        }
        if (f == 0)
        {
            cout << 0;
        }
        cout << endl;
        return;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
}
bool cmp(int a, int b)
{
    if (a == 4 && b == 40)
        return false;
    if (a == 40 && b == 4)
        return true;
    if (a == 8 && b == 80)
        return false;
    if (a == 80 && b == 8)
        return true;
    pair<int, int> x, y;
    x.first = a % 10;
    x.second = a / 10;
    y.first = b / 10;
    y.second = b % 10;
    if (x.first < x.second)
        swap(x.first, x.second);
    if (y.first < y.second)
        swap(y.first, y.second);
    if (x == y)
        return b < a;
    return x < y;
}
void work()
{
    memset(dij, 0, sizeof dij);
    ans.clear();
    for (int i = 0; i < 10; i++)
    {
        cin >> dij[i];
    }
    if (dij[0] >= 2)
    {
        out();
        return;
    }
    vector<int> hd;
    for (int i = 1; i < 100; i++)
    {
        if (i % 4 == 0)
        {
            hd.push_back(i);
        }
    }
    sort(hd.begin(), hd.end(), cmp);
    for (int i = 0; i < hd.size(); i++)
    {
        cout << "i=" << i << " hd[i]=" << hd[i] << endl;
    }
    for (int i = 0; i < hd.size(); i++)
    {
        if (dij[hd[i] % 10] && (hd[i] / 10 == 0 || dij[hd[i] / 10]))
        {
            ans.push_back(hd[i] % 10);
            dij[hd[i] % 10]--;
            if (hd[i] / 10 != 0)
            {
                ans.push_back(hd[i] / 10);
                dij[hd[i] / 10]--;
            }
            out();
            return;
        }
    }
    if (dij[0])
        cout << 0 << endl;
    else
        cout << -1 << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}