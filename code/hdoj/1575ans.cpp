#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int mod = 9973;
typedef long long ll;
int n;
struct node
{
    int n;
    int date[100][100];
    node operator+(node a)
    {
        int t = max(n, a.n);
        node k;
        k.n = t;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                k.date[i][j] = date[i][j] + a.date[i][j];
            }
        }
        return k;
    }
    node operator*(node a)
    {
        node x;
        node s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
        int t, s;
        if (n / 2 == 0)
        {
            t = n / 2;
        }
        else
        {
            t = n / 2 + 1;
        }
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
            }
        }
        s2 = A11 + A12;
        s3 = A21 + A22;
        s4 = B21 - B11;
        s5 = A11 + A22;
        s6 = B11 + B22;
        s7 = A12 - A22;
        s8 = B21 + B22;
        s9 = A11 - A21;
        s10 = B11 + B12;

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
    node ans;
    ans.n = n;
    ans = cst;
    if (x == 1)
    {
        return ans;
    }
    node k;
    k.n = n;
    k = cst;
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
    cst.n = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cst.date[i][j]);
        }
    }
    int ans = 0;
    node k;
    k.n = n;
    k = pow(x);
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