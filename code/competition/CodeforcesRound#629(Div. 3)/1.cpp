#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
const int mod = (0 ? 1000000007 : 998244353);
void work()
{
    int a, b;
    cin >> a >> b;
    if (a % b == 0)
    {
        cout << 0 << endl;
        return;
    }
    {
        cout << (a / b + 1) * b - a << endl;
    }
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