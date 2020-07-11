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
    int x, n;
    int tmp;
    cin >> n >> x;
    vector<int> v;
    int tol = 0;
    int ans = llinf;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tol += tmp;
        v.push_back(tmp);
    }
    if (tol < x)
    {
        cout << -1 << endl;
        return;
    }
    int tail = 0;
    int head;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        now += v[i];
        if (now >= x)
        {
            head = i;
            break;
        }
    }
    ans = min(ans, head - tail + 1);
    while (now >= x)
    {
        now -= v[tail];
        tail++;
    }
    tail--;
    now += v[tail];
    ans = min(ans, head - tail + 1);
    while (head < n - 1)
    {
        head++;
        now += v[head];
        while (now >= x)
        {
            now -= v[tail];
            tail++;
        }
        tail--;
        now += v[tail];
        ans = min(ans, head - tail + 1);
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