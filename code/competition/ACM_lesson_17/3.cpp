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
    string tmp;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            int jie = 0;
            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j] <= '9' && tmp[j] >= '0')
                {
                    jie *= 10;
                    jie += tmp[j] - '0';
                }
            }
            cout << jie * 513 << endl;
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}