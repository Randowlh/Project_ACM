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
    int tol = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tol += tmp;
        v.push_back(tmp);
    }
    double ans = (double)tol / n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= ans)
            cnt++;
    }
    printf("%.2lf ", ans);
    cout << cnt << endl;
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}