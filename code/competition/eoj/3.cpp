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
struct node
{
    string date;
    node(string a) : date(a) {}
    bool operator<(const node &a) const
    {
        if (date.size() == a.date.size())
            return date < a.date;
        else
            return date.size() < a.date.size();
    }
};
struct cmp
{
    bool operator()(const string a, const string b) const
    {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};
void work()
{
    set<node> s;
    string tmp;
    int m, n;
    node tt("1");
    cin >> m >> n;
    m++;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tt.date = tmp;
        s.insert(tt);
    }
    int tol = 0;
    for (auto j = s.begin(); j != s.end(); j++)
    {
        if ((*j).date.size() + 1 <= m)
        {
            m -= (*j).date.size() + 1;
            tol++;
        }
        else
            break;
    }
    cout << tol << endl;
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