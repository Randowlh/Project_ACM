#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void work()
{
    int n;
    cin >> n;
    int tmp;
    int ans = 0;
    int now = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
    int date[5][2];
    memset(date, 0, sizeof(date));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (date[j][0] != 0 || j == 0)
                date[(j + v[i]) % 5][1] = max(date[(j + v[i]) % 5][0], date[j][0] + v[i]);
        }
        for (int j = 0; j < 5; j++)
        {
            date[j][0] = max(date[j][0], date[j][1]);
        }
    }
    cout << date[0][0] << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}