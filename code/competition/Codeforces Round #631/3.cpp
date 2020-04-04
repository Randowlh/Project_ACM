#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n, m;
    cin >> n >> m;
    int tmp;
    vector<int> v;
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
    int cnt = m;
    int last = n;
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (cnt + v[i] - 1 < n)
        {
            ans.push_back(last - v[i] + 1);
            cnt--;
            cnt += v[i];
            last -= v[i];
        }
        else
        {
            ans.push_back(m - i);
            last = m - i - 1;
            break;
        }
    }
    for (int i = last; i >= 1; i--)
    {
        ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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