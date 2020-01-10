#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
        return gcd(b, a % b);
}
void work()
{
    ll a, b, c, d;
    scanf("%lld/%lld",&a,&b);
    scanf("%lld/%lld",&c,&d);
    ll chu=b/gcd(b,d)*d;
    a*=chu/b;
    c*=chu/d;
    ll fz=a/gcd(a,c)*c;
    if(fz%chu==0){
        cout<<fz/chu<<endl;
    }else{
        ll tmp=gcd(fz,chu);
        fz/=tmp;
        chu/=tmp;
        cout<<fz<<'/'<<chu<<endl;
    }
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}