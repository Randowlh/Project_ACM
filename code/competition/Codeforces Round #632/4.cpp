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
    int n, k;
    cin >> n >> k;
    string tmp;
    cin >> tmp;
    int mid = tmp.size() / 2;
    int ma = 0;
    int tol = 0;
    vector<pair<int, int>> ni;
    for (int i = 0; i < mid; i++)
    {
        if (tmp[i] == 'R')
        {
            ma = max(ma, mid - i);
            tol += mid - i;
            ni.push_back(make_pair(mid - i, i));
        }
    }
    for (int i = mid; i < tmp.size(); i++)
    {
        if (tmp[i] == 'L')
        {
            ma = max(i - mid + 1, ma);
            tol += mid;
        }
    }
    cout << tol << ' ' << ma << endl;
    if (tol < k || k < ma)
    {
        cout << -1 << endl;
        return;
    }
    int res = k - ma;
    sort(ni.begin(), ni.end());
    vector<vector<int>> ans;
    int now = 0;
    while (true)
    {
        vector<int> t;
        t.clear();
        if (res == 0)
            break;
        t.push_back(ni[now].second);
        ni[now].second++;
        ni[now].first--;
        if (ni[now].first == 0)
            now++;
        ans.push_back(t);
        res--;
    }
    for (int i = 0; i < ma; i++)
    {
        vector<int> t;
        for (int j = 0; j < ni.size(); j++)
        {
            if (ni[j].first != 0)
            {
                cout << "ni[i]" << ni[j].first << ' ' << ni[j].second << endl;
                t.push_back(ni[j].second);
                ni[j].first--;
                ni[j].second++;
            }
        }
        ans.push_back(t);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << ' ';
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] + 1 << ' ';
        }
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