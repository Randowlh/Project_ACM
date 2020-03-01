#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    int ma = 0;
    int tmp = 0;
    vector<int> v;
    int maa = 0;
    int mi = inf;
    int mii = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > ma)
        {
            maa = i;
            ma = tmp;
        }
        if (tmp < mi)
        {
            mi = tmp;
            mii = i;
        }
        v.push_back(tmp);
    }
    //cout << ma << ' ' << mi << endl;
    int ans = 0;
    int dis = (maa - mii + n) % n;
    // cout << dis << endl;
    for (int i = 0; i < dis; i++)
    {
        int tp = 0;
        int flag[410];
        memset(flag, 1, sizeof(flag));
        for (int j = mii; j < mii + i; j++)
        {
            if (flag[j % n])
            {
                flag[j % n] = 0;
                tp += abs(mi - v[j % n]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (flag[j])
            {
                tp += abs(ma - v[j]);
            }
        }
        ans = max(ans, tp);
    }
    for (int i = 0; i < n - dis - 1; i++)
    {
        int tp = 0;
        int flag[410];
        memset(flag, 1, sizeof(flag));
        for (int j = maa; j < maa + i; j++)
        {
            if (flag[j % n])
            {
                flag[j % n] = 0;
                tp += abs(ma - v[j % n]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (flag[j])
            {
                tp += abs(mi - v[j]);
            }
        }
        ans = max(ans, tp);
    }
    cout << ans << endl;
}
int main()
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