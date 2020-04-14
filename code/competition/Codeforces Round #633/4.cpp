#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
vector<int> mp[100100];
int book[100100];
struct node
{
    int dpt;
    pair<int, int> x;
};
node dfs(int pos)
{
    book[pos] = 1;
    node tmp;
    int mi = 0, mx = 0;
    int ji[2] = {0, 0};
    set<int> s;
    int dpth = 0;
    for (int i = 0; i < mp[pos].size(); i++)
    {
        if (book[mp[pos][i]] == 0)
        {
            tmp = dfs(mp[pos][i]);
            s.insert(tmp.dpt % 2);
            mx += tmp.x.second;
            dpth = max(dpth, tmp.dpt);
        }
    }
    mi = s.size();
    pair<int, int> ans(mi + 1, mx + 1);
    node a;
    a.x = ans;
    a.dpt = dpth;
    return a;
}
void work()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    pair<int, int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i].size() > 1)
        {
            ans = dfs(i).x;
            break;
        }
    }
    cout << ans.first - 1 << ' ' << ans.second - 1 << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}