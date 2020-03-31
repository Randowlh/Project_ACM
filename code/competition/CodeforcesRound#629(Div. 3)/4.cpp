#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    int cnt = 0;
    int pr = -1231314;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        if (tmp != pr)
        {
            cnt++;
            pr = tmp;
        }
    }
    if (cnt == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }
    if (cnt % 2 == 1)
    {
        cout << 2 << endl;
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            if (pr == v[i])
            {
                cout << f << ' ';
                continue;
            }
            else
            {
                pr = v[i];
                cout << f << ' ';
                if (f == 1)
                    f = 2;
                else
                    f = 1;
            }
        }
        cout << endl;
        return;
    }
    if (cnt == n)
    {
        cout << 3 << endl;
        int f = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cout << f << ' ';
            if (f == 1)
                f = 2;
            else
                f = 1;
        }
        cout << 3 << endl;
        return;
    }
    pr = 123142424;
    for (int i = 0; i < n; i++)
    {
        if (pr == v[i])
        {
            v[i - 1] = 129047192;
            break;
        }
    }
    cout << 2 << endl;
    pr = 312412414;
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        if (pr == v[i])
        {
            cout << f << ' ';
            continue;
        }
        else
        {
            pr = v[i];
            cout << f << ' ';
            if (f == 1)
                f = 2;
            else
                f = 1;
        }
    }
    cout << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}