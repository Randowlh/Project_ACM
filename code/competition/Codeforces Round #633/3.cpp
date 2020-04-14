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
    int n;
    int tmp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int mx = v[0];
    int mxx = 0;
    for (int i = 1; i < n; i++)
    {
        mxx = max(mxx, mx - v[i]);
        mx = max(v[i], mx);
    }
    int cnt = 0;
    int now = 0;
    int add = 1;
    while (now < mxx)
    {
        now += add;
        add <<= 1;
        cnt++;
    }
    cout << cnt << endl;
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