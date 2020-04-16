#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
inline int calc(int a, int b, int c)
{
    return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}
void work()
{
    int nr, nb, ng;
    cin >> nr >> nb >> ng;
    vector<int> r, b, g;
    int tmp;
    for (int i = 0; i < nr; i++)
    {
        cin >> tmp;
        r.push_back(tmp);
    }
    for (int i = 0; i < nb; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    for (int i = 0; i < ng; i++)
    {
        cin >> tmp;
        g.push_back(tmp);
    }
    int ans = 9223372036854775807;
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    sort(r.begin(), r.end());
    vector<int>::iterator it;
    vector<int> t1, t2;
    for (int i = 0; i < nr; i++)
    {
        it = lower_bound(b.begin(), b.end(), r[i]);
        if (it != b.end())
            t1.push_back(*it);
        if (it - 1 >= b.begin())
            t1.push_back(*(it - 1));
        it = lower_bound(g.begin(), g.end(), r[i]);
        if (it != g.end())
            t2.push_back(*it);
        if (it - 1 >= g.begin())
            t2.push_back(*(it - 1));
        for (int j = 0; j < t1.size() && !t1.empty(); j++)
        {
            for (int k = 0; k < t2.size() && !t2.empty(); k++)
            {
                //  cout << t1[j] << ' ' << t2[j] << endl;
                ans = min(ans, calc(t1[j], t2[k], r[i]));
            }
        }
        t1.clear();
        t2.clear();
    }
    for (int i = 0; i < ng; i++)
    {
        it = lower_bound(r.begin(), r.end(), g[i]);
        if (it != r.end())
            t1.push_back(*it);
        if (it - 1 >= r.begin())
            t1.push_back(*(it - 1));
        it = lower_bound(b.begin(), b.end(), g[i]);
        if (it != b.end())
            t2.push_back(*it);
        if (it - 1 >= b.begin())
            t2.push_back(*(it - 1));
        for (int j = 0; j < t1.size() && !t1.empty(); j++)
        {
            for (int k = 0; k < t2.size() && !t2.empty(); k++)
            {
                //  cout << t1[j] << ' ' << t2[j] << endl;
                ans = min(ans, calc(t1[j], t2[k], g[i]));
            }
        }
        t1.clear();
        t2.clear();
    }
    for (int i = 0; i < nb; i++)
    {
        it = lower_bound(r.begin(), r.end(), b[i]);
        if (it != r.end())
            t1.push_back(*it);
        if (it - 1 >= r.begin())
            t1.push_back(*(it - 1));
        it = lower_bound(g.begin(), g.end(), b[i]);
        if (it != g.end())
            t2.push_back(*it);
        if (it - 1 >= g.begin())
            t2.push_back(*(it - 1));
        for (int j = 0; j < t1.size() && !t1.empty(); j++)
        {
            for (int k = 0; k < t2.size() && !t2.empty(); k++)
            {
                //  cout << t1[j] << ' ' << t2[j] << endl;
                ans = min(ans, calc(t1[j], t2[k], b[i]));
            }
        }
        t1.clear();
        t2.clear();
    }
    cout << ans << endl;
}
signed main()
{
    // cout << LONG_LONG_MAX << endl;
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