#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
string date[] = {"AC", "AD", "BC", "BD"};
void work()
{
    int ac[4];
    //cin >> ac >> ad >> bc >> bd;
    for (int i = 0; i < 4;i++){
        cin >> ac[i];
    }
    int mix = -1;
    int mx = llinf;
    for (int i = 0; i < 4;i++){
        if(ac[i]<mx){
            mx = ac[i];
            mix = i;
        }
    }
    if(a[i])
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}