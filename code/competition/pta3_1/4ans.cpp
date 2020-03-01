#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
inline bool cmp(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return a.size() > b.size();
}
int dfs(vector<int> v)
{
    int ans = 0;
    if (v.size() <= 1)
    {
        return 0;
    }
    int ma = 0;
    int mai = 0;
    int mi = inf;
    int mii = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < mi)
        {
            mi = v[i];
            mii = i;
        }
        if (v[i] > ma)
        {
            ma = v[i];
            mai = i;
        }
    }
    ans += ma - mi;
    vector<int> a;
    for (int i = 1; i <= v.size(); i++)
    {
        if ((mii + i) % v.size() != mai)
            a.push_back(v[(mii + i) % v.size()]);
        else
            break;
    }
    vector<int> b;
    for (int i = 1; i <= v.size(); i++)
    {
        if ((mii - i + v.size()) % v.size() != mai)
            b.push_back(v[(mii - i + v.size()) % v.size()]);
        else
            break;
    }
    if (cmp(a, b))
    {
        a.push_back(ma);
        ans += dfs(a);
    }
    else
    {
        b.push_back(ma);
        ans += dfs(b);
    }
    return ans;
}
void work()
{
    int n;
    int tmp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    ll ans = 0;
    ans = dfs(v);
    cout << ans << endl;
}
int main()
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