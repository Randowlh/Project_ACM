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
    int k = 0;
    cin >> k;
    int date[10];
    for (int i = 0; i < 10; i++)
        date[i] = 1;
    int tt = 1;
    int now = 0;
    while (tt < k)
    {
        tt /= date[now];
        date[now]++;
        tt *= date[now];
        now++;
        now %= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < date[i]; j++)
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
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}