#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
map<pair<int, int>, int> M;
void calc(int a, int b)
{
    for (int i = a; i <= b; i++)
        for (int j = i; j <= b; j++)
            M[make_pair(i, j)]++;
}
void work()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            calc(i, j);
    for (auto i = M.begin(); i != M.end(); i++)
    {
        cout << "pair" << (i->first).first << "->" << (i->first).second << "is" << i->second << endl;
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