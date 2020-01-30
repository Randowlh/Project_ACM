#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
void work()
{
    ll a, m;
    cin >> a >> m;
    ll k = gcd(a, m);
    a /= k;
    m /= k;
    ll tol = m - a - 1;
    vector<int> ys;
    int tmp=m;
    for (int i = 0; i <= sqrt(m); i++)
    {
        if (m % i == 0)
        {
            ys.push_back(i);
            while(m%i==0){
                m/=i;
            }
        }
    }
    if(m!=1){
        ys.push_back(m);
    }
    m=tmp;
    int cnt;
    for(int i=0;i<ys.size();i++){
        ll e=(a/ys[i]+1)*ys[i];
        cnt-=(m-e)/ys[i]  ;    
    } 
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