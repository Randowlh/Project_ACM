#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x + y < n + 1)
    {
        cout << 1 << ' ';
        if (x + y - 1 <= n)
        {
            cout << x + y + 1;
        }
        else
            cout << n;
    }
    else
    {
        if (x + y - n + 1 <= n)
        {
            cout << x + y - n + 1 << ' ';
        }
        else
            cout << n << ' ';
        if (x + y - 1 <= n)
            cout << x + y + 1 << ' ';
        else
            cout << n << endl;
    }
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