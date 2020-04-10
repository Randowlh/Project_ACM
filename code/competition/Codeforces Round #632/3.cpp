#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> v, c;
    set<int> s;
    s.insert(0);
    map<int, int> M;
    int pr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        c.push_back(tmp - pr);
        pr = tmp;
    }
    int sum = 0;
    int cnt = 0;
    int ans = 0;
    int last = -1;
    M[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (M.count(sum) == 0)
            ans += i - last;
        else
        {
            ans += i - max(last, M[sum] + 1);
            last = max(last, M[sum] + 1);
        }
        M[sum] = i;
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