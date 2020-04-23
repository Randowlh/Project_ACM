#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n, tmp;
vector<int> v, now;
void dfs(int step, int nw)
{
    if (step == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << now[i] << ' ';
        }
        cout << now[5] << endl;
        return;
    }
    for (int i = nw + 1; i <= n - 6 + step; i++)
    {
        now.push_back(v[i]);
        dfs(step + 1, i);
        now.pop_back();
    }
}
void work()
{
    int f = 0;
    while (cin >> n, n)
    {
        if (f)
            cout << endl;
        else
            f = 1;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i <= n - 6; i++)
        {
            now.push_back(v[i]);
            dfs(1, i);
            now.pop_back();
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}