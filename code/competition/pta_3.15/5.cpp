#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, k;
    cin >> n >> k;
    if (k > 2)
    {
        return;
    }
    else
    {
        cout << 0 << endl;
        int mi = inf;
        vector<pair<int, int>> v;
        pair<int, int> x;
        for (int i = 0; i < n; i++)
        {
            cin >> x.first >> x.second;
            v.push_back(x);
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                mi = min(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second), mi);
            }
        cout << mi << endl;
    }
}
int main()
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