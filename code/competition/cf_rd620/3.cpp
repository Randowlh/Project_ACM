#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int t;
    int l;
    int u;
    bool operator<(node a)
    {
        return t < a.t;
    }
};
void work()
{
    int n, m;
    cin >> n >> m;
    vector<node> v;
    node tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.t >> tmp.l >> tmp.u;
        v.push_back(tmp);
    }
    int nowl = m;
    int nowu = m;
    int nowt = 0;
    for (int i = 0; i < n; i++)
    {
        nowl -= v[i].t - nowt;
        nowu += v[i].t - nowt;
        nowt = v[i].t;
        if (nowu < v[i].l || nowl > v[i].u)
        {
            cout << "NO" << endl;
            return;
        }
        nowl = max(nowl, v[i].l);
        nowu = min(nowu, v[i].u);
    }
    cout << "YES" << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}