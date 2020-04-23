#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
vector<int> gs, lo, rt;
int n;
vector<int> ans;
bool Judge(int x)
{
    for (int i = 0; i < gs.size(); i++)
    {
        int cntl = 0;
        int cntr = 0;
        map<int, int> s;
        int tx = x;
        int tg = gs[i];
        for (int j = 0; j < 4; j++)
        {
            if (tx % 10 == tg % 10)
                cntl++;
            s[tg % 10]++;
            tx /= 10;
            tg /= 10;
        }
        tx = x;
        for (int j = 0; j < 4; j++)
        {
            if (s[tx % 10])
            {
                cntr++;
                s[tx % 10]--;
            }
            tx /= 10;
        }
        if (cntr != rt[i] || cntl != lo[i])
            return false;
    }
    return true;
}
void work()
{
    while (cin >> n, n)
    {
        ans.clear();
        gs.clear();
        lo.clear();
        rt.clear();
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            gs.push_back(a);
            lo.push_back(c);
            rt.push_back(b);
        }
        for (int i = 1000; i <= 9999; i++)
        {
            if (Judge(i))
            {
                ans.push_back(i);
                // cout << i << endl;
            }
        }
        if (ans.size() == 1)
        {
            cout << ans[0] << endl;
        }
        else
            cout << "Not sure" << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}