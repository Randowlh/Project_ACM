#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int a, b;
    cin >> a >> b;
    if (b == a + 1)
    {
        cout << a << ' ' << b << endl;
        return;
    }
    if (a == b)
    {
        cout << a << 0 << ' ' << b << 1 << endl;
        return;
    }
    else if (a == 9 && b == 1)
    {
        cout << 9 << ' ' << 10 << endl;
    }
    else
        cout << -1 << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}