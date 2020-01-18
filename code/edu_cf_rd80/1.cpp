#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll qushang(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
void work()
{
    ll n, d;
    cin >> n >> d;
    if(n>=d){
        cout<<"YES"<<endl;
        return;
    }
    for (int i = 1; i <=(int) sqrt(d); i++)
    {
        if ((i+qushang(d,i+1))<=n){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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