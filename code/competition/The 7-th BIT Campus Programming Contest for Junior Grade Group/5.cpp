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
int tt[100];
void work()
{
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld%lld", &a, &b);
        a--;
        b--;
        if (a > b)
            swap(a, b);
        if (b - a >= 41)
        {
            printf("yes\n");
            continue;
        }
        for (int j = a; j <= b; j++)
        {
            tt[j - a] = v[j];
        }
        int f = 0;
        sort(tt, tt + b - a + 1);
        for (int j = 0; j + 2 < b - a + 1; j++)
        {
            if ((tt[j + 2] - tt[j + 1] - tt[j]) < 0)
            {
                f = 1;
                break;
            }
        }
        if (f)
            printf("yes\n");
        else
            printf("no\n");
    }
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        work();
    }
    return 0;
}