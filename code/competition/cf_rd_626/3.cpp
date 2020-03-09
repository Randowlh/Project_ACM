#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int n;
    string tmp;
    cin >> n >> tmp;
    if (n & 1)
    {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    int num = 0;
    int ans = 0;
    int pr = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] == ')')
        {
            num--;
        }
        else if (tmp[i] == '(')
        {
            num++;
        }
        if (num >= 0)
        {
            if (cnt != 0)
                ans += cnt + 1;
            cnt = 0;
        }
        else
            cnt++;
        //  cout << num << ' ' << cnt << endl;
    }
    if (num != 0)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
    return 0;
}