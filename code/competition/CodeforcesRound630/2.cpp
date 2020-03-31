#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int mp[101];
    memset(mp, 0, sizeof(mp));
    vector<int> v[101];
    int n;
    cin >> n;
    vector<int> date;
    vector<int> d;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        d.push_back(0);
        date.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j * j <= date[i]; j++)
        {
            if (date[i] % j == 0)
            {
                v[j].push_back(i);
                d[i] = j;
                break;
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < 101; i++)
    {
        if (v[i].size() != 0)
        {
            mp[i] = cnt;
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mp[d[i]] << ' ';
    }
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}