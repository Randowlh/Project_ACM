#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcms(int a, int b) { return a * b / gcd(a, b); }
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        int t = v[i];
        for (int j = 2; j * j <= t; j++)
        {
            if (t % j == 0)
            {
                M[j]++;
                if (j != t / j)
                    M[t / j]++;
            }
        }
        M[t]++;
        M[1]++;
    }
    int ans = 1;
    vector<int> est;
    for (auto i = M.begin(); i != M.end(); i++)
    {
        if (i->second >= n - 1)
            est.push_back(i->first);
    }
    for (int i = 0; i < est.size(); i++)
    {
        ans = lcms(ans, est[i]);
    }
    cout << ans << endl;
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