#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n, m;
    int tmp;
    vector<int> v;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    if (sum < n)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    int last = n;
    int kk = m;
    for (int i = 0; i < m; i++)
    {
        int tt = last - v[i] + 1;
        if (tt < 1)
        {
            cout << -1 << endl;
            return;
        }
        if (sum - v[i] + 1 < n)
        {

            ans.push_back(tt);
            last = sum - v[i];
            kk = i + 1;
            break;
        }
        sum -= v[i];
        ans.push_back(tt);
        last--;
        n--;
    }
    for (int i = kk; i < m; i++)
    {
        int tt = last - v[i] + 1;
        if (tt < 1)
        {
            cout << -1 << endl;
            //return;
        }
        ans.push_back(tt);
        last -= v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}