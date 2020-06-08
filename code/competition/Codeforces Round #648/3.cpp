#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        M[v[i]] = i;
        cin >> tmp;
        v2.push_back(tmp);
    }
    map<int, int> dis;
    for (int i = 0; i < n; i++)
    {
        dis[(i - M[v2[i]] + n) % n]++;
    }
    int ans = 0;
    for (auto i = dis.begin(); i != dis.end(); i++)
    {
        ans = max(ans, i->second);
    }
    cout << ans << endl;
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