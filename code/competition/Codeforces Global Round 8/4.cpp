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
int b[100];
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        int cnt = 0;
        while (tmp)
        {
            if (tmp & 1)
                b[cnt]++;
            tmp >>= 1;
            cnt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int now = 0;
        for (int j = 0; j < 23; j++)
        {
            if (b[j])
            {
                b[j]--;
                now += 1 << j;
            }
        }
        ans += now * now;
    }
    cout << ans << endl;
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