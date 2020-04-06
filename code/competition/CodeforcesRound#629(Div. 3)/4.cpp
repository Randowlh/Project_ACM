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
    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++)
        cin >> tmp, v.push_back(tmp);
    v.push_back(v[0]);
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++)
        v[i] ^ v[i + 1] ? cnt++ : 0;
    if (cnt == 0)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
        cout << endl;
    }
    else if (cnt % 2 == 0)
    {
        cout << 2 << endl;
        int pr = v[0];
        int now = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != pr)
                if (now == 1)
                    now = 2;
                else
                    now = 1;
            cout << now << ' ';
            pr = v[i];
        }
        cout << endl;
    }
    else if (cnt == n)
    {
        cout << 3 << endl;
        int now = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cout << now << ' ';
            if (now == 1)
                now = 2;
            else
                now = 1;
        }
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == v[i + 1])
            {
                v[i] = mod;
                break;
            }
        }
        int pr = v[0];
        int now = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != pr)
                if (now == 1)
                    now = 2;
                else
                    now = 1;
            cout << now << ' ';
            pr = v[i];
        }
        cout << endl;
    }
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}