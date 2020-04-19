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
    double a = 0;
    int n;
    cin >> n;
    double tmp;
    vector<double> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > v[(i + 1) % v.size()])
        {
            a += 1 / v[i];
        }
        else
        {
            a += 1 / v[(i + 1) % v.size()];
        }
    }
    printf("%.2f\n", a);
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}