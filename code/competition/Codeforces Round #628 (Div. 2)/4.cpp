#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll u, v;
    cin >> u >> v;
    if (u > v)
    {
        cout << -1 << endl;
        return;
    }
    if (u == 0 && v == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (u == v)
    {
        cout << 1 << endl;
        cout << u << endl;
        return;
    }
    if ((v - u) & 1)
    {
        cout << -1 << endl;
        return;
    }
    ll tmp = v - u;
    tmp >>= 1;
    int f = 0;
    ll ut = u;
    ll tt = tmp;
    while (ut && tt)
    {
        if ((ut & 1) && (tt & 1))
        {
            f = 1;
            break;
        }
        ut >>= 1;
        tt >>= 1;
    }
    if (f)
    {
        cout << 3 << endl;
        cout << u << ' ' << tmp << ' ' << tmp << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << u + tmp << ' ' << tmp << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}