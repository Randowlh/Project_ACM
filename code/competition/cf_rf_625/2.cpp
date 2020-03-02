#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
map<int, ll> m;
void work()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        m[tmp - i] += tmp;
    }
    ll ma = 0;
    map<int, ll>::iterator iter = m.begin();
    while (iter != m.end())
    {
        ma = max(ma, iter->second);
        iter++;
    }
    cout << ma << endl;
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