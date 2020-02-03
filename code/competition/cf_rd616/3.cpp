#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int n, m, k, u;
vector<int> v;

int check(int l, int r)
{
    int tmx = inf;
    for (int j = l; j < u + l; j++)
    { // cout<<j<<' '<<n - (m - j)<<endl;
        tmx = min(tmx, max(v[j], v[n - (m - j)]));
    }
    /*
    for (int j = r; j > r - u; j--)
    {
        tmx = min(tmx, max(v[j], v[n - (m - j)]));
    }*/
    return tmx;
}
void work()
{
    //int n,m,k;
    cin >> n >> m >> k;
    //vector<int> v;
    v.clear();
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    int mx = -1;
    if (m - 1 < k)
    {
        k = m - 1;
    }
    // m--;
    u = m - k;
    mx=-1;
    for (int i = 0; i <= k; i++)
    {
        //cout << "l=" << i << ' ' << n - 1 - k + i << endl;
        int tmx = check(i, n - 1 - (k + i));

        mx = max(tmx, mx);
    }
    cout << mx << endl;
    return;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}