#include <bits/stdc++.h>
using namespace std;
int date[100010];
int cnt[100010][2], cnt1, ans;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
        date[i] %= 2;
    }
    for (int i = 0; i < n / k + 1; i++)
        for (int j = 0; j < k; j++)
        {
            int t = i * k + j;
            if (t >= n)
                continue;
            cnt[j][date[t]]++;
        }
    for (int i = 0; i < k; i++)
    {
        if (cnt[i][0] < cnt[i][1])
            cnt1++, ans += cnt[i][0];
        else
            ans += cnt[i][1];
    }
    if (cnt1 % 2 == 1)
    {
        int delta = 0x7FFFFFFF;
        for (int j = 0; j < k; j++)
        {
            if (cnt[j][0] < cnt[j][1])
                delta = min(delta, cnt[j][1] - cnt[j][0]);
            else
                delta = min(delta, cnt[j][0] - cnt[j][1]);
        }
        ans += delta;
    }
    cout << ans << endl;
    return 0;
}