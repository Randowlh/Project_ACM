#include <bits/stdc++.h>
using namespace std;
struct node
{
    int w, v, num;
    bool operator<(node a)
    {
        if (w == a.w)
        {
            return v > a.v;
        }
        return w < a.w;
    }
    bool operator!=(node a)
    {
        if (w < a.w && v > a.v)
        {
            return true;
        }
        return false;
    }
};
int dp[110000];
int pr[110000];
int main()
{
    vector<node> v;
    node x;
    int cnt = 1;
    while (cin >> x.w >> x.v)
    {
        x.num = cnt;
        v.push_back(x);
        cnt++;
    }
    sort(v.begin(), v.end());
    pr[0] = -1;
    dp[0] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        int mix = -1;
        int ma = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] != v[i])
            {
                if (ma < dp[j] + 1)
                {
                    mix = j;
                    ma = dp[j] + 1;
                }
            }
        }
        pr[i] = mix;
        dp[i] = ma;
    }
    int mxx = -1;
    int ma = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (dp[i] > ma)
        {
            ma = dp[i];
            mxx = i;
        }
    }
    vector<int> ans;
    int p = mxx;
    while (p != -1)
    {
        ans.push_back(v[p].num);
        p = pr[p];
    }
    cout << (int)ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }
    return 0;
}