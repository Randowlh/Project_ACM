#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int x, y;
    bool operator<(node a)
    {
        return x + y < a.x + a.y;
    }
};
void work()
{
    vector<pair<int, int>> v, e;
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> x;
    node xx;
    for (int i = 0; i < k; i++)
    {
        cin >> x.first >> x.second;
        v.push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> xx.x >> xx.y;
        e.push_back(x);
    }
    sort(e.begin(), e.end());
    string ans;
    int ma = -1;
    for (int i = 0; i < v.size(); i++)
    {
        ma = max(v[i].first, ma);
    }
    for (int i = 1; i < ma; i++)
        ans.push_back('U');
    ma = -1;
    for (int i = 0; i < v.size(); i++)
    {
        ma = max(v[i].second, ma);
    }
    for (int i = 1; i < ma; i++)
        ans.push_back('L');
    int f = 0;
    for (int i = 1; i < m; i++)
    {
        if (f == 0)
        {
            for (int i = 1; i < n; i++)
                ans.push_back('D');
            f = 1;
        }
        else
        {
            for (int i = 1; i < n; i++)
                ans.push_back('U');
            f = 0;
        }
        ans.push_back('R');
    }
    if (f == 0)
    {
        for (int i = 1; i < n; i++)
            ans.push_back('D');
        f = 1;
    }
    else
    {
        for (int i = 1; i < n; i++)
            ans.push_back('U');
        f = 0;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}