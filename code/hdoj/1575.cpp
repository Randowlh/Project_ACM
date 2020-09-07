#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 9973;
typedef long long ll;
int n;
struct node
{
    // int n;
    int date[100][100];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                for (int k = 0; k < n; k++)
                {
                    ans = ans + date[i][k] * a.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                date[i][j] = a.date[i][j];
        return *this;
    }
} cst;
node pow(ll x)
{
    node ans = cst;
    if (x == 1)
    {
        return ans;
    }
    node k = cst;
    x--;
    ll tmp = 1;
    while (tmp <= x)
    {
        ans = ans * k;
        k = k * k;
        x -= tmp;
        tmp *= 2;
    }
    if (x != 0)
    {
        ans = ans * pow(x);
    }
    return ans;
}
void work()
{
    ll x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cst.date[i][j]);
        }
    }
    int ans = 0;
    node k = pow(x);
    for (int i = 0; i < n; i++)
    {
        ans += k.date[i][i];
    }
    ans %= mod;
    cout << ans << endl;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}