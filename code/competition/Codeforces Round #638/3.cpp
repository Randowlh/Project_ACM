#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int n, k;
    cin >> k >> n;
    string tmp;
    cin >> tmp;
    sort(tmp.begin(), tmp.end());
    if (n == 1)
    {
        cout << tmp << endl;
        return;
    }
    string ans, ans1;
    int now = 0;
    for (int i = n - 1; i < tmp.size(); i++)
    {
        ans1.push_back(tmp[i]);
    }
    while (now != tmp.size())
    {
        set<int> s;
        for (int i = 0; i < n && now < tmp.size(); i++)
        {
            s.insert(tmp[now]);
            now++;
        }
        ans.push_back(*s.rbegin());
        if (s.size() > 1)
            break;
    }
    cout << min(ans, ans1) << endl;
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