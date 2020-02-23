#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<ll> v;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    ll ans = 0;
    vector<ll> t;
    vector<ll> an;
    for (int i = 0; i < n; i++)
    {
        t.clear();
        t = v;
        ll tmp = v[i];
        ll pr = tmp;
        for (int j = i - 1; j >= 0; j--)
        {
            if (t[j] > pr)
            {
                t[j] = pr;
            }
            tmp += t[j];
            pr = t[j];
        }
        pr = v[i];
        for (int j = i + 1; j < n; j++)
        {
            if (t[j] > pr)
            {
                t[j] = pr;
            }
            tmp += t[j];
            pr = t[j];
        }
        if (ans < tmp)
        {
            //  cout << tmp << endl;
            an = t;
            ans = tmp;
        }
    }
    for (int i = 0; i < an.size(); i++)
    {
        cout << an[i] << ' ';
    }
    cout << endl;
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