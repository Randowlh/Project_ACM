#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
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
    string a;
    string b;
    while (cin >> a >> b)
    {
        int f = 1;
        if (a.size() > b.size())
        {
            swap(a, b);
            f = 0;
        }
        b += b;
        string tt = a;
        while (a.size() < b.size())
        {
            a += tt;
        }
        int flag = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] > a[i])
            {
                flag = -1;
                break;
            }
            if (b[i] < a[i])
            {
                flag = 1;
                break;
            }
        }
        if (f)
            flag = -flag;
        if (flag == -1)
        {
            cout << ">" << endl;
        }
        else if (flag == 0)
        {
            cout << '=' << endl;
        }
        else
        {
            cout << "<" << endl;
        }
    }
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}