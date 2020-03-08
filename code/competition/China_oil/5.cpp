#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
const int mod = 1000000007;
typedef long long ll;
struct node
{
    int n;
    ll date[40][40];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                ll ans = 0;
                for (int k = 0; k < n; k++)
                {
                    ans = ans + date[i][k] * a.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    void operator=(node a)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                date[i][j] = a.date[i][j];
        return;
    }
    node operator+(node a)
    {
        node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                x.date[i][j] = (a.date[i][j] + date[i][j]) % mod;
            }
        return x;
    }
} e, cst, no;
node pow(ll x)
{
    node ans = e;
    node k = cst;
    //ll tmp = 1;
    while (x > 0)
    {
        if (x & 1)
            ans = ans * k;
        x >>= 1;
        k = k * k;
    }
    return ans;
}
node pow_sum(int k)
{
    if (k == 0)
    {
        return e;
    }
    cout << k << endl;
    if (k == 1)
        return e;
    node last = pow_sum(k / 2);
    last = (e + pow(k / 2)) * last;
    if (k % 2)
        last = last + pow(k);
    return last;
}
void work()
{
    int n, k;
    cin >> n >> k;
    e.n = n;
    for (int i = 0; i <= n; i++)
    {
        e.date[i][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cst.date[i][j];
        }
    }
    cst.n = n;
    vector<int> ji;
    while (k != 0)
    {
        ji.push_back(k);
        k /= 2;
    }
    node ans = cst;
    for (int i = ji.size() - 1; i > 0; i--)
    {
        ans = ans * (e + pow(ji[i]));
        if (ji[i - 1] & 1)
            ans = ans + pow(ji[i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans.date[i][j] << ' ';
        }
        cout << endl;
    }
    return;
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