#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<int> v1, v2, a;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v2.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        a.push_back(v1[i] - v2[i]);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            int z = upper_bound(a.begin(), a.end(), -a[i]) - a.begin();
            ans += (n - z);
        }
        else
        {
            ans += (ll)(n - i - 1) * (ll)(n - i) / 2;
            break;
        }
    }
    cout << ans << endl;
}
int main()
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