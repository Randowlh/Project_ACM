#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll k;
    // cout << (int)('y' - 'a') << endl;
    cin >> k;
    if (k == 0)
    {
        cout << 'a' << endl;
        return;
    }
    ll tol = k / ('z' - 'a');
    char fl = 'a';
    cout << fl;
    if (tol == 0)
    {
        cout << (char)('a' + k % ('z' - 'a')) << endl;
        return;
    }
    int jian = 'z' - 'a' - k % ('z' - 'a');
    cout << (char)('z' - jian / 2);
    if (jian % 2 == 0)
        jian = 0;
    else
        jian = 1;
    for (int i = 0; i < tol - 1; i++)
    {
        cout << fl;
        if (fl == 'a')
        {
            fl = 'z';
        }
        else
        {
            fl = 'a';
        }
    }
    if (fl == 'a')
    {
        cout << (char)('a' + jian);
    }
    else
    {
        cout << (char)('z' - jian);
    }
    cout << endl;

    // cout << (int)('o' - 'a') << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}