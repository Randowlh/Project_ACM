#include <bits/stdc++.h>
using namespace std;
int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int n, m, p;
    vector<int> a, b;
    int tmp;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % p != 0)
        {
            ans += i;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] % p != 0)
        {
            ans += i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}