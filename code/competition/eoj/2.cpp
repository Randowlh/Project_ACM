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
inline int dis(int x, int y, int z)
{
    return x * x + y * y + z * z;
}
void work()
{
    int n;
    vector<int> a, b, c;
    int ta, tb, tc;
    cin >> n;
    int ma = llinf;
    int mix;
    for (int i = 0; i < n; i++)
    {
        cin >> ta >> tb >> tc;
        if (dis(ta, tb, tc) < ma)
        {
            ma = dis(ta, tb, tc);
            mix = i;
        }
    }
    printf("%.3f\n", sqrt(ma));
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}