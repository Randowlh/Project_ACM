#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int a, b, c;
int aa, bb, cc;
int ans = inf;
inline int calc(int ta, int tb, int tc)
{
    return abs(ta - a) + abs(tb - b) + abs(tc - c);
}
void dfs(int ta, int tb, int step)
{
    if (step == 1)
    {
        for (int i = 1; ta * i <= c + 20000; i++)
        {
            dfs(ta, ta * i, 2);
        }
    }
    else
    {
        if (ans > calc(ta, tb, c / tb * tb))
        {
            ans = calc(ta, tb, c / tb * tb);
            aa = ta;
            bb = tb;
            cc = c / tb * tb;
        }
        if (ans > calc(ta, tb, (c / tb + 1) * tb))
        {
            ans = calc(ta, tb, (c / tb + 1) * tb);
            aa = ta;
            bb = tb;
            cc = (c / tb + 1) * tb;
        }
        return;
    }
}
void work()
{
    ans = inf;
    cin >> a >> b >> c;
    for (int i = 1; i <= c; i++)
    {
        dfs(i, 0, 1);
    }
    cout << ans << endl;
    cout << aa << ' ' << bb << ' ' << cc << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}