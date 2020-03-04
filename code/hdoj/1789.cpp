#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int x, d;
    bool operator<(node a)
    {
        if (x == a.x)
        {
            return d < a.d;
        }
        else
            return x > a.x;
    }
};
void work()
{
    int n;
    cin >> n;
    vector<node> date;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        node a;
        cin >> a.d;
        date.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> date[i].x;
    }
    s.clear();
    sort(date.begin(), date.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int f = 0;
        for (int j = date[i].d; j > 0; j--)
        {
            if (s.count(j) == 0)
            {
                s.insert(j);
                f = 1;
                break;
            }
        }
        if (!f)
        {
            ans += date[i].x;
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
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}