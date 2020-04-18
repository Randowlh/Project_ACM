#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct node
{
    string name, temp, xh;
    bool operator<(node a)
    {
        if (name == a.name)
        {
            if (temp == a.temp)
                return xh < a.xh;
            else
                return temp > a.temp;
        }
        return name > a.name;
    }
};
void work()
{
    node a;
    vector<node> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a.name >> a.xh >> a.temp;
        v.push_back(a);
    }
    int cnt = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].temp >= "38.0")
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
    {
        if (v[i].temp >= "38.0")
            cout << v[i].name << ' ' << v[i].xh << ' ' << v[i].temp << endl;
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