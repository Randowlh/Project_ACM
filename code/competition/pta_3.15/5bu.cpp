#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll ans[100010];
int x[100010], y[100010];
ll tmp[100010];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        ans[i] = LONG_LONG_MAX;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int tt = 0; tt < n; tt++)
            {
                tmp[tt] = abs(x[i] - x[tt]) + abs(y[j] - y[tt]);
            }
            sort(tmp, tmp + n);
            for (int tt = 1; tt < n; tt++)
            {
                tmp[tt] += tmp[tt - 1];
            }
            for (int tt = 0; tt < n; tt++)
            {
                ans[tt] = min(ans[tt], tmp[tt]);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}