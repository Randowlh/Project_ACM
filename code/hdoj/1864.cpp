#include <bits/stdc++.h>
using namespace std;
int dp[3000010];
int ck(string tmp)
{
    double biao[] = {0, 0, 0};
    int ans = 0;
    stringstream ss(tmp);
    int n;
    ss >> n;
    for (int i = 0; i < n; i++)
    {
        string tt;
        ss >> tt;
        int k = tt[0] - 'A';
        if (k < 0 || k >= 3)
        {
            return -1;
        }
        stringstream ss2(tt.substr(2, 999999));
        double a;
        ss2 >> a;
        biao[k] += a;
    }
    double tol = 0;
    for (int i = 0; i < 3; i++)
    {
        if (biao[i] > 600)
            return -1;
        tol += biao[i];
    }
    if (tol > 1000)
        return -1;
    return (int)(tol * 100);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    double tmp;
    int n, m;
    while (cin >> tmp >> n, n)
    {
        getchar();
        m = (int)(tmp * 100);
        string t;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            getline(cin, t);
            int tt = ck(t);
            if (tt != -1)
            {
                v.push_back(tt);
            }
        }
        for (int i = 0; i <= m; i++)
        {
            dp[i] = 0;
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = m; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
            }
        }
        printf("%.2f\n", dp[m] / 100.0);
    }
}