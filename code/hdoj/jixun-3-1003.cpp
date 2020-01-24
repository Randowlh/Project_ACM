#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
int n, mod;
struct node
{
    // int n;
    int date[100][100];
    node operator*(node a)const
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
} cst;
node pows(int x)
{   
    
    //cout << "ES"<<x << endl;
    if (x == 1)
    {
        return cst;
    }
    node ans = cst;
    node k = cst;
    ll tmp = 1;
    x--;
    while (x >= tmp)
    {
        ans = ans * k;
        x = x - tmp;
        tmp = tmp + tmp;
        k = k * k;
    }
    if (x != 0)
    {
        ans = ans * pows(x);
    }
    
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int k;
    scanf("%d%d%d", &n, &k, &mod);
    // cout << n << ' ' << k << ' ' << mod << endl;
    for (int i = 0; i < n * 2; i++)
        for (int j = 0; j < n * 2; j++)
        {
            cst.date[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cst.date[i][j]);
            cst.date[i][j + n] = cst.date[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cst.date[n + i][n + i] = 1;
    }
    /*
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            cout << cst.date[i][j] << ' ';
        }
        cout << endl;
    }*/
    n = n * 2;
    // cout << n << endl;
    node x = pows(k);
    n = n / 2;
    //cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < n * 2; j++)
        {
            printf("%d ", x.date[i][j]);
        }
        printf("\n");
    }
    return 0;
}