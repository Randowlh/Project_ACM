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
    int n, x;
    cin >> n >> x;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int len = unique(v.begin(), v.end()) - v.begin();
    int cnt = 0;
    int pr = 0;
    //cout << x << endl;
    for (int i = 0; i < len; i++)
    {
        if (cnt + v[i] - pr - 1 > x)
        {
            cout << pr + x - cnt << endl;
            return;
        }
        cnt += v[i] - pr - 1;
        pr = v[i];
    }
    cout << pr + x - cnt << endl;
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