#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], ans[100005];
long long s;
int main()
{
    int i, x = 0;
    scanf("%d%d", &m, &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]), s += a[i];
    for (i = 1; i <= n; i++)
        if (m - a[i] < i - 1)
        {
            cout << -1 << endl;
            return 0;
        }
    if (s < m)
    {
        printf("-1");
        return 0;
    }
    for (i = 1; i < n; i++)
        ans[i] = i;
    ans[n] = m - a[i] + 1;
    for (i = n - 1; i; i--)
        if (ans[i] + a[i] < ans[i + 1])
            ans[i] = ans[i + 1] - a[i];
        else
            break;
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
