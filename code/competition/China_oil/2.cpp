#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    ll v;
    ll t;
    bool operator<(node a)
    {
        return t * a.v < a.t * v;
    }
};
void work()
{
    int n;
    cin >> n;
    vector<node> v;
    node x;
    for (int i = 0; i < n; i++)
    {
        cin >> x.v >> x.t;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll now = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        now += v[i].t;
        ans += now * v[i].v;
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