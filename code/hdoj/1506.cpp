#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l[110000], r[110000];
ll date[110000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    ll tmp;
    int n;
    while (cin >> n, n)
    {

        for (int i = 0; i < n; i++)
        {
            cin >> date[i];
        }
        for (int i = 0; i < n; i++)
        {
            l[i] = i;
            while (l[i] > 0 && date[i] <= date[l[i] - 1])
                l[i] = l[l[i] - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            r[i] = i;
            while (r[i] < n - 1 && date[i] <= date[r[i] + 1])
                r[i] = r[r[i] + 1];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (r[i] - l[i] + 1) * date[i]);
        }
        cout << ans << endl;
    }
}
