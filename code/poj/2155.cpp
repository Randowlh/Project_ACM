#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll tree[1110][1110];
int n;
inline int lowbit(int x) { return x & -x; }
void update(int x, int y, int v)
{
    for (int i = x; i <= 1000; i += lowbit(i))
        for (int j = y; j <= 1000; j += lowbit(j))
        {
            tree[i][j] += v;
            // cout << "??" << endl;
        }
}
ll query(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            ans += tree[i][j];
    return ans;
}
void change(int x1, int y1, int x2, int y2)
{
    update(x1, y1, 1);
    update(x1, y2 + 1, -1);
    update(x2 + 1, y1, -1);
    update(x2 + 1, y2 + 1, 1);
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        memset(tree, 0, sizeof(tree));
        int n, Q;
        cin >> n >> Q;
        char C;
        int a, b, c, d;
        for (int i = 0; i < Q; i++)
        {
            cin >> C;
            if (C == 'C')
            {
                cin >> a >> b >> c >> d;
                change(a, b, c, d);
            }
            else
            {
                cin >> a >> b;
                cout << (int)(query(a, b) & 1) << endl;
            }
        }
        if (q != t - 1)
        {
            cout << endl;
        }
    }
    return 0;
}