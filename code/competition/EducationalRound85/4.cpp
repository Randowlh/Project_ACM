#include <bits/stdc++.h>
using namespace std;
#define int long long
void work()
{
    int n, l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    int sum = 0;
    int f = 0;
    for (int i = n - 1; i > 0; i--)
    {

        //cout << "sum=" << sum << " cnt=" << cnt << endl;
        sum += i * 2;
        cnt++;
        if (sum > l)
        {
            sum -= i * 2;
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        if (l == sum + 1)
            cout << 1 << endl;
        return;
    }
    vector<int> ans;
    int fl = l % 2;
    // cout << fl << endl;
    int now = cnt + fl + (l - sum) / 2;
    //cout << "cnt=" << cnt << "  now=" << now << endl;
    for (int i = l; i <= r; i++)
    {
        if (fl == 1)
        {
            if (cnt == n)
            {
                ans.push_back(1);
                break;
            }
            ans.push_back(cnt);
            fl = 0;
        }
        else
        {
            fl = 1;
            ans.push_back(now);
            if (now == n)
            {
                cnt++;
                now = cnt + 1;
            }
            else
                now++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}