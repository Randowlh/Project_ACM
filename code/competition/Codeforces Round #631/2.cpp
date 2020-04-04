#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
int m[200100];
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v, tt;
    int ma = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ma = max(ma, tmp);
        v.push_back(tmp);
    }
    if (ma >= n)
    {
        cout << "0\n0\n";
        return;
    }
    int cnt = 0;
    m[n - 1] = v[n - 1];
    set<int> s;
    s.insert(v[n - 1]);
    int f = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (f)
        {
            m[i] = 0;
            continue;
        }
        if (s.count(v[i]) != 0)
        {
            m[i] = 0;
            f = 1;
            continue;
        }
        s.insert(v[i]);
        m[i] = max(v[i], m[i + 1]);
        if (m[i] < n - i)
        {
            m[i] = 0;
            f = 1;
            continue;
        }
    }
    set<int> ss;
    vector<pair<int, int>> ans;
    int maa = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (ss.count(v[i]) != 0)
            break;
        ss.insert(v[i]);
        maa = max(maa, v[i]);
        if (maa < i + 1)
        {
            break;
        }
        if (m[i + 1] == n - i - 1 && maa == i + 1)
        {
            ans.push_back(make_pair(i + 1, n - i - 1));
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}