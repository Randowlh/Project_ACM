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
    sort(v.begin(), v.end());
    vector<int> ans, a, b;
    int now = n / 2;
    int f = 1;
    int taila = 0, tailb = 0;
    for (int i = 0; i < now; i++)
    {
        a.push_back(v[i]);
    }
    reverse(a.begin(), a.end());
    for (int i = now; i < n; i++)
    {
        b.push_back(v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (f)
        {
            f = 0;
            ans.push_back(b[tailb]);
            tailb++;
        }
        else
        {
            f = 1;
            ans.push_back(a[taila]);
            taila++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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