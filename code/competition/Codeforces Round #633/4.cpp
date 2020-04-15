#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
vector<int> mp[100010];
bool bfs(int s)
{
    unordered_set<int> book;
    book.insert(s);
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (mp[now.first].size() == 1 && now.second % 2 == 1)
        {
            return false;
        }
        for (int i = 0; i < mp[now.first].size(); i++)
        {
            if (book.count(mp[now.first][i]) == 0)
            {
                book.insert(mp[now.first][i]);
                q.push(make_pair(mp[now.first][i], now.second + 1));
            }
        }
    }
    return true;
}
void work()
{
    int n;
    cin >> n;
    int a, b;
    map<int, int> M;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        M[a]++;
        M[b]++;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    map<int, int>::iterator it;
    int root = 0;
    vector<int> lvs;
    for (it = M.begin(); it != M.end(); it++)
    {
        if (it->second == 1)
        {
            root = it->first;
            lvs.push_back(root);
        }
    }
    if (bfs(root))
        cout << 1 << ' ';
    else
        cout << 3 << ' ';
    map<int, int> cal;
    for (int i = 0; i < lvs.size(); i++)
    {
        cal[mp[lvs[i]][0]]++;
    }
    int ans = 0;
    for (it = cal.begin(); it != cal.end(); it++)
    {
        if (it->second > 1)
        {
            ans += it->second - 1;
        }
    }
    cout << n - 1 - ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}