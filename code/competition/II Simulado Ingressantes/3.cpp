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
void work()
{
    int x, y;
    cin >> x >> y;
    int tx, ty;
    while(true){
        if(!(x&&y)){
            if(x){
                cout << 1 << ' ' << x << endl;
            }else
                cout << 2 << ' ' << y << endl;
            break;
        }
        if(x>1){
            cout << 1 << ' ' << x - 1 << endl;
            x = 1;
        }else
        if(y>1){
            cout<<2<<' '<<y - 1 << endl;
            y = 1;
        }
        cout.flush();
        cin >> tx >> ty;
        if(tx==1)
            x -= ty;
        else
            y -= ty;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}