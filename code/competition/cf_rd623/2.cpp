#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
struct node
{
    int val;
    int len;
    bool operator<(node a)
    {
        int x1, x2;
        x2 = lcm(val, a.val) / val * len;
        x1 = lcm(val, a.val) / a.val * a.len;
        return x1 > x2;
    }
};
void work()
{
    int a[2], m;
    cin >> a[0] >> a[1] >> m;
    string tmp;
    cin >> tmp;
    vector<node> v;
    char fl = tmp[0];
    int cnt = 1;
    for (int i = 1; i < tmp.size(); i++)
    {
        if (fl == tmp[i])
        {
            cnt++;
            continue;
        }
        node x;
        x.len = cnt;
        cnt = 1;
        x.val = a[fl - 'A'];
        v.push_back(x);
        fl = tmp[i];
    }
    if (cnt != 0)
    {
        node x;
        x.len = cnt;
        cnt = 1;
        x.val = a[fl - 'A'];
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int tol = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i].len << ' ' << v[i].val << endl;
        if (v[i].val <= m)
        {
            m -= v[i].val;
            tol += v[i].len;
        }
    }
    cout << tmp.size() - tol << endl;
}
int main()
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