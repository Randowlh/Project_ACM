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
    int n, k;
    cin >> n >> k;
    int tmp;
    vector<int> v, c;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        c.push_back(tmp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (n - i + 1 + c[v[i] - 1] - 1) / c[v[i] - 1]);
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j += ans)
            cnt++;
        cout << cnt << ' ';
        for (int j = i; j < n; j += ans)
            cout << v[j] << ' ';
        cout << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}