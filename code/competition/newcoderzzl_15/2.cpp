#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    int tmp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            ans += (i + 1) * tmp;
        }
        else
            ans += tmp;
    }
    cout << ans << endl;
}