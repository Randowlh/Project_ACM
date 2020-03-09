#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int w, v;
    int num;
    bool operator<(node a)
    {
        if (v == a.v)
            return w < a.w;
        return v > a.v;
    }
    bool operator>(node a)
    {
        return w > a.w && v < a.v;
    }
};
int dp[10000];
int pr[10000];
void work()
{
    vector<node> v;
    node a;
    int cnt = 0;
    while (cin >> a.w >> a.v)
    {
        cnt++;
        a.num = cnt;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= 1100; i++)
    {
        dp[i] = 1;
    }
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i < 10; i++)
    {
        cout << dp[i] << endl;
    }
    pr[0] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        int mix = i;
        int tmp = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                if (tmp < dp[j] + 1)
                {
                    mix = j;
                    tmp = dp[j] + 1;
                }
            }
            dp[i] = tmp;
            pr[i] = mix;
        }
    }
    int now = 0;
    int ma = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (dp[i] > ma)
        {
            ma = dp[i];
            now = i;
        }
    }
    cout << ma << endl;
    vector<int> ans;
    ans.push_back(now + 1);
    while (true)
    {
        now = pr[now];
        ans.push_back(v[now].num);
        if (now == pr[now])
            break;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << endl;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}