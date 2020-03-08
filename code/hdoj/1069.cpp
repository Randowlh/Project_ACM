#include <bits/stdc++.h>
using namespace std;
struct node
{
    int w, l, h;
    bool operator<(node a)
    {
        if (w == a.w)
        {
            return l > a.l;
        }
        return w > a.w;
    }
    void made(int a, int b, int c)
    {
        w = a;
        l = b;
        h = c;
        return;
    }
    bool operator>(node a)
    {
        if (w < a.w && l < a.l)
            return true;
        return false;
    }
};
int n;
vector<node> arr;
int dp[510000];
int main()
{
    //freopen("in.txt", "r", stdin);
    int cnt = 0;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        arr.clear();
        cnt++;
        node x;
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            x.made(a, b, c);
            arr.push_back(x);
            x.made(b, a, c);
            arr.push_back(x);
            x.made(a, c, b);
            arr.push_back(x);
            x.made(c, a, b);
            arr.push_back(x);
            x.made(c, b, a);
            arr.push_back(x);
            x.made(b, c, a);
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        dp[0] = arr[0].h;
        for (int i = 1; i < arr.size(); i++)
        {
            int tmp = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    tmp = max(tmp, dp[j] + arr[i].h);
                }
            }
            tmp = max(tmp, arr[i].h);
            dp[i] = tmp;
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(dp[i], ans);
        }
        cout << "Case " << cnt << ": maximum height = " << ans << endl;
    }
    return 0;
}