#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
#define int long long
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int date[100000];
int sz[100000];
int find(int x)
{
    if (date[x] == x)
        return x;
    else
        return date[x] = find(date[x]);
}
void merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l != r)
    {
        sz[l] += sz[r];
        date[r] = l;
    }
}
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
map<int, int> M;
void work()
{
    for (int i = 0; i < 19990; i++)
    {
        sz[i] = 1;
        date[i] = i;
    }
    int n = 0;
    cin >> n;
    int x, y;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (M[x] == 0)
        {
            M[x] = cnt;
            cnt++;
        }
        if (M[y] == 0)
        {
            M[y] = cnt;
            cnt++;
        }
        merge(M[x], M[y]);
    }
    int cntt = 0;
    for (int i = 1; i < cnt; i++)
    {
        if (find(i) == i && sz[i] == 1)
        {
            cntt++;
        }
    }
    if (cntt % 2 != 0)
    {
        cout << "zyh" << endl;
    }
    else
        cout << "fzj" << endl;
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