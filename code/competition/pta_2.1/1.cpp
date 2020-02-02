#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
int dis[10010];
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
    int n;
    ll tmpa, tmpb;
    ll a, b;
    a = 0;
    b = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &tmpa, &tmpb);
        if (tmpb == 0)
            continue;
        int k = tmpb;
        tmpa *= b;
        tmpb *= b;
        a *= k;
        b *= k;
        a += tmpa;
        ll x = gcd(a, b);
        a /= x;
        b /= x;
    }
    ll x = gcd(a, b);
    a /= x;
    b /= x;
    if (a % b == 0)
        cout << a/b << endl;
    else if (a / b != 0)
        cout << a / b << ' ' << a % b << '/' << b << endl;
    else
        cout << a << '/' << b << endl;
}
int main()
{   
    
    //freopen("in.txt","r",stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}






