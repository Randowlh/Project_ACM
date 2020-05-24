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
map<char, int> M[100];
void work()
{
    int n, m;
    cin >> n >> m;
    string tmp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < 100; i++)
    {
        M[i].clear();
    }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            M[j][v[i][j]]++;
    string ans;
    ans.clear();
    int tol = 0;
    for (int i = 0; i < m; i++)
    {
        int ma = 0;
        char maa;
        for (auto j = M[i].begin(); j != M[i].end(); j++)
        {
            if (j->second > ma)
            {
                ma = j->second;
                maa = j->first;
            }
        }
        tol += ma;
        //cout << ma << endl;
        ans.push_back(maa);
    }
    // cout << "tol=" << tol << endl;
    if (tol + n < n * m)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (ans[j] != v[i][j])
                cnt++;
        }
        if (cnt > 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}