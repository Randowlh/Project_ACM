#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    int r, b, k;
    for (int q = 0; q < t; q++)
    {
        cin >> r >> b >> k;
        int tt = gcd(r, b);
        r /= tt;
        b /= tt;
        if (b < r)
        {
            swap(b, r);
        }
        if ((b - 2) / r + 1 >= k)
        {
            cout << "REBEL" << endl;
        }
        else
            cout << "OBEY" << endl;
    }
    return 0;
}