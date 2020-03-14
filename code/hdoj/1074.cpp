#include <bits/stdc++.h>
using namespace std;
struct node
{
    int time, score, past;
} dp[1 << 15];
struct cl
{
    string name;
    int ddl, cst;
};
int n;
vector<cl> v;
int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        v.clear();
        cin >> n;
        cl x;
        for (int i = 0; i < n; i++)
        {
            cin >> x.name >> x.ddl >> x.cst;
            v.push_back(x);
        }
        int tn = 1 << n;
        dp[0].past = 0;
        dp[0].score = 0;
        dp[0].time = 0;
        for (int i = 1; i < tn; i++)
        {
            dp[i].score = 99999999;
            for (int j = v.size() - 1; j >= 0; j--)
            {
                if (i & (1 << j))
                {
                    int past = i - (1 << j);
                    int ans = dp[past].time + v[j].cst - v[j].ddl;
                    int ma = ans > 0 ? ans : 0;
                    if (dp[past].score + ma < dp[i].score)
                    {
                        dp[i].score = dp[past].score + ma;
                        dp[i].past = past;
                        dp[i].time = dp[past].time + v[j].cst;
                    }
                }
            }
        }
        cout << dp[tn - 1].score << endl;
        vector<int> out;
        int p = tn - 1;
        while (p)
        {
            out.push_back(p - dp[p].past);
            p = dp[p].past;
        }
        for (int i = out.size() - 1; i >= 0; i--)
        {
            int a = 0;
            out[i] >>= 1;
            while (out[i])
            {
                out[i] >>= 1;
                a++;
            }
            cout << v[a].name << endl;
        }
    }
}
