#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
bool mp[100][100];
int heng[100];
int shu[100];
void work()
{
    int n, m;
    cin >> n >> m;
    memset(heng, 0, sizeof(heng));
    memset(shu, 0, sizeof(shu));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j])
            {
                shu[j] = 1;
                heng[i] = 1;
            }
        }
    int cnth = 0, cnts = 0;
    for (int i = 0; i < n; i++)
    {
        if (heng[i] == 0)
            cnth++;
    }
    for (int i = 0; i < m; i++)
    {
        if (shu[i] == 0)
            cnts++;
    }
    //cout << cnth << ' ' << cnts << endl;
    if (min(cnts, cnth) % 2 == 0)
        cout << "Vivek" << endl;
    else
        cout << "Ashish" << endl;
}
signed main()
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