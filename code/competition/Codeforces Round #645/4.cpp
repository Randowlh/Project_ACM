#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp1[410000], dp2[410000];
vector<int> v;
signed main()
{
    //freopen("in.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(v[i]);
    }
    dp1[0] = v[0];
    dp2[0] = v[0] * (v[0] + 1) / 2;
    for (int i = 1; i < n * 2; i++)
    {
        dp1[i] = dp1[i - 1] + v[i];
        dp2[i] = dp2[i - 1] + v[i] * (v[i] + 1) / 2;
    }
    n *= 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int pr = upper_bound(dp1, dp1 + n, dp1[i] - x) - dp1;
        if (!pr)
            continue;
        int jian = dp1[i] - x - dp1[pr - 1];
        jian = jian * (jian + 1) / 2;
        ans = max(ans, dp2[i] - dp2[pr - 1] - jian);
    }
    cout << ans << endl;
}