#include <bits/stdc++.h>
using namespace std;
struct node
{
    double x, y;
};
inline double dis(node a, node b, node c)
{
    return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
inline bool jiao(node a, node b, node c, node d)
{
    double t1 = dis(a, b, c);
    double t2 = dis(a, b, d);
    double t3 = dis(c, d, a);
    double t4 = dis(c, d, b);
    if (t1 * t2 <= 0 && t3 * t4 <= 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<pair<node, node>> v;
        pair<node, node> x;
        for (int i = 0; i < n; i++)
        {
            cin >> x.first.x >> x.first.y >> x.second.x >> x.second.y;
            v.push_back(x);
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (jiao(v[i].first, v[i].second, v[j].first, v[j].second))
                {
                    ans++;
                }
            }
        cout << ans << endl;
    }
    return 0;
}