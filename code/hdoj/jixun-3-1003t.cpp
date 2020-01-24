#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, mod;
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
} cst,e;
/*
node cheng(node a,node b){
    node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                for (int k = 0; k < n; k++)
                {
                    ans = ans + a.date[i][k] * b.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
}*/
node pow(ll x)
{   //cout<<"??"<<' '<<x<<endl;
    node ans = e;
    node k = cst;
    //ll tmp = 1;
    while (x>0)
    {
        if(x&1)
        ans =  ans*k;
        x >>=1;
        k=k*k;
    }
    return ans;
}
void work()
{
    ll k;
    cin >> n >> k >> mod;
    // cout << n << ' ' << k << ' ' << mod << endl;
    for (int i = 0; i < n * 2; i++)
        for (int j = 0; j < n * 2; j++)
        {   e.date[i][j]=0;
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
    for(int i=0;i<n*2;i++){
        e.date[i][i]=1;
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
    node x = pow(k);
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
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    ll t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}