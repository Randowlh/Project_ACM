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
int n, m;
int cnt[100];
string ans;
int flag;
vector<string> v;
void dfs(int now)
{
    if (now == m)
    {
        cout << ans << endl;
        flag = 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        char t = v[i][now];
        int f = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j][now] != t && cnt[j])
            {
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        set<int> s;
        for (int j = 0; j < n; j++)
        {
            if (v[j][now] != t)
            {
                s.insert(j);
                cnt[j]++;
            }
        }
        ans.push_back(t);
        dfs(now + 1);
        if (flag)
            return;
        ans.pop_back();
        for (auto k = s.begin(); k != s.end(); k++)
        {
            cnt[*k]--;
        }
    }
}
void work()
{
    v.clear();
    ans.clear();
    flag = 0;
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> m;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    dfs(0);
    if (!flag)
        cout << -1 << endl;
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