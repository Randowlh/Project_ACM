#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    ll n;
    cin >> n;
    vector<ll> v;
    v.clear();
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    ll mia = -999;
    vector<ll> ans;
    ans.clear();
    ll pr = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (pr != -1 && v[i] != -1)
        {
            mia = max(abs(pr - v[i]), mia);
        }
        else if (pr == -1 && v[i] == -1)
        {
            continue;
        }
        else if (pr == -1)
        {
            ans.push_back(v[i]);
        }
        else if (v[i] == -1)
        {
            ans.push_back(pr);
        }
        pr = v[i];
    }
    if (ans.empty() && mia == -999)
    {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    ll k = (ans[0] + ans[ans.size() - 1]) / 2;
    ll m = mia;
    m = max(m, max(abs(k - ans[0]), abs(ans[ans.size() - 1] - k)));
    cout << m << ' ' << k << endl;
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}