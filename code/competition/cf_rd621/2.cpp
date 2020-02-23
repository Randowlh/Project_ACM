#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, x;
    cin >> n >> x;
    vector<int> v;
    int tmp;
    int fl = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (x == tmp)
        {
            fl = 1;
        }
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    if (fl)
    {
        cout << 1 << endl;
        return;
    }
    if (x / v[v.size() - 1] == 0)
    {
        cout << 2 << endl;
    }
    else if (x % v[v.size() - 1] == 0)
    {
        cout << x / v[v.size() - 1] << endl;
    }
    else
        cout << x / v[v.size() - 1] + 1 << endl;
    return;
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