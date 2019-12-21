#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int inf = 0x7FFFFFFF;
map<int, int> mp;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        mp.clear();
        int n;
        cin >> n;
        int date[200100];
        int a = 0;
        for (int i = 0; i < n * 2; i++)
        {
            scanf("%d", &date[i]);
            if (date[i] == 1)
                a++;
            else
                a--;
        }
        // cout<<a<<"test"<<endl;
        int cnt = 0;
        if (a == 0)
        {
            cout << 0 << endl;
            continue;
        }
        // map<int, int> mp;
        for (int i = n; i < n * 2; i++)
        {
            if (date[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (mp[cnt] == 0)
            {
                // cout<<i-n+1<<' '<<cnt<<"r"<<endl;
                mp[cnt] = i - n + 1;
            }
        }
        int ans = inf;
        cnt = a;
        if (mp[cnt])
        {
            ans = mp[cnt];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (date[i] == 1)
            {
                cnt--;
            }
            else
                cnt++;
            if (cnt == 0)
            { //cout<<i<<' '<<cnt<<"ee"<<endl;
                ans = min(ans, n - i );
            }
            if (mp[cnt] != 0)
            {
                //cout << cnt << ' ' << ans << ' ' << mp[cnt] << endl;
                ans = min(ans, n - i  + mp[cnt]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}