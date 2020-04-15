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
        //   cout << "sum=" << sum << ' ' << "cnt=" << cnt << endl;
        sum += i * 2;
        cnt++;
        if (sum >= l)
        {
            sum -= i * 2;
            f = 1;
            break;
        }
    }
    if (f == 0)
    { //最后一个数特判
        if (l == sum + 1)
            cout << 1 << endl;
        return;
    }
    //  cout << cnt << "cnt" << endl;
    vector<int> ans;
    int fl = l % 2;                     //1奇数项2偶数项
    int now = cnt + fl + (l - sum) / 2; //偶数项加到的数
                                        // cout << now << ' ' << cnt << ' ' << fl << ' ' << l - sum << endl;
    //cnt是奇数项加到的数
    for (int i = l; i <= r; i++)
    {
        if (fl == 1)
        {
            if (cnt == n)
            { //结尾特判
                ans.push_back(1);
                break;
            }
            //奇数
            ans.push_back(cnt);
            fl = 0;
        }
        else
        {
            fl = 1;
            //偶数
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
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}