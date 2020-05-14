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
int dp[110000];
int n;
vector<int> v;
int getmax(int now)
{
    if (dp[now] != -1)
        return dp[now];
    int ans = 0;
    int nw = 2;
    while (nw * now <= n)
    {
        if (v[nw * now] > v[now])
        {
            ans = max(ans, getmax(nw * now));
        }
        nw++;
    }
    ans++;
    dp[now] = ans;
    return ans;
}
void work()
{
    cin >> n;
    int tmp;
    v.clear();
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[n] = -1;
    int ma = 0;
    for (int i = 1; i <= n; i++)
    {
        ma = max(ma, getmax(i));
    }
    cout << ma << endl;
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