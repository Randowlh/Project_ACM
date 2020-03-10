#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, k;
    cin >> n >> k;
    set<int> s;
    ll now = 0;
    vector<ll> v;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            continue;
        int cnt = 0;
        ll t = v[i];
        while (true)
        {
            if (t == 1)
            {
                if (s.count(cnt) != 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                s.insert(cnt);
                break;
            }
            if (t % k == 0)
            {
                t /= k;
                cnt++;
            }
            else
            {
                if ((t - 1) % k == 0)
                {
                    if (s.count(cnt) != 0)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    else
                    {
                        s.insert(cnt);
                        t--;
                        t /= k;
                        cnt++;
                        continue;
                    }
                }
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}