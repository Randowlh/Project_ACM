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
struct node
{
    int c, b;
    bool operator<(node a) const
    {
        return c < a.c;
    }
};
void work()
{
    int n;
    vector<node> v;
    cin >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].c;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].b;
    }
    vector<int> aa, bb;
    for (int i = 0; i < n; i++)
    {
        if (v[i].b)
            aa.push_back(v[i].c);
        else
            bb.push_back(v[i].c);
    }
    stable_sort(v.begin(), v.end());
    int flag = 0;
    int tail1 = 0, tail2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].b)
        {
            if (aa[tail1] != v[i].c)
            {
                out(0);
                return;
            }
            else
                tail1++;
        }
        else
        {
            if (bb[tail2] != v[i].c)
            {
                out(0);
                return;
            }
            else
                tail2++;
        }
    }
    out(1);
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