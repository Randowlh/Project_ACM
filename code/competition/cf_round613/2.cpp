#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;

ll maxSum(ll a[], ll n, ll &begin, ll &end)
{
    ll sum = 0; 
    ll tem = 0; 
    for (int i = 0; i < n; i++)
    {
        if (tem > 0)
            tem += a[i]; 
        else
        {
            tem = a[i];
            begin = i;
        }
        if (tem > sum)
        {
            sum = tem;
            end = i; 
        }
    }
    return sum;
}

void work()
{
    int n;
    cin >> n;
    ll date[100010];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>date[i];
            sum += date[i];
    }
    ll b,e;
    ll tmp=maxSum(date,n,b,e);
    if(b==0&&e==n-1){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}