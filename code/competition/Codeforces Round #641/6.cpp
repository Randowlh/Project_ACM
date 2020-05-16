#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
struct node
{

    int a, b;
    node(int aa, int bb) : a(aa), b(bb) {}
    bool operator>(node aa) const
    {
        return a < aa.a;
    }
};
void work()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    priority_queue<node, vector<node>, greater<node>>
        q;
    q.push(node(1, 2));
    q.push(node(2, 2));
    q.push(node(3, 4));
    while (!q.empty())
    {
        q.pop();
    }
}
signed main()
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