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
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int w, h, k;
inline bool ck(int x, int y)
{
    if (x < 0 || x >= w)
        return false;
    if (y < 0 || y >= h)
        return false;
    return true;
}
vector<pair<int, int>> r;
char mp[110][110];
int b[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int step)
{
    if (step > k)
        return 0;
    for (int j = 0; j < r.size(); j++)
    {
        pair<int, int> bk = r[j];
        for (int i = 0; i < 4; i++)
        {
            int now = 1;
            while (true)
            {
                if (!ck(bk.first + b[i][0] * now, bk.second + b[i][1] * now))
                    break;
                char &t = mp[bk.first + b[i][0] * now][bk.second + b[i][1] * now];
                if (t == 'X' || t == 'R')
                    break;
                now++;
            }
            now--;
            pair<int, int> lo(bk.first + b[i][0] * now, bk.second + b[i][1] * now);
            if (mp[lo.first][lo.second] == 'D')
                return 1;
            r[j] = lo;
            swap(mp[lo.first][lo.second], mp[bk.first][bk.second]);
            if (dfs(step + 1))
                return 1;
            r[j] = bk;
            swap(mp[lo.first][lo.second], mp[bk.first][bk.second]);
        }
    }
    return 0;
}
void work()
{
    r.clear();
    cin >> h >> w >> k;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'R')
                r.push_back(make_pair(i, j));
        }
    out(dfs(1));
}
signed main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}