#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    string a, b, c;
    cin >> a >> b >> c;
    int fl = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == c[i] || b[i] == c[i])
            continue;
        else
            fl = 0;
    }
    if (fl)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}