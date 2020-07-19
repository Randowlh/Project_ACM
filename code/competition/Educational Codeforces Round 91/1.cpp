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
    int n;
    cin >> n;
    int tmp;
    vector<int> v;
    for (int i = 0; i < n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    int f = 0;
    vector<int> ans;
    for (int i = 0;i<v.size()-1;i++){
        if(v[i]<v[i+1]&&!f){
        f = 1;
        ans.push_back(i+1);
        ans.push_back(i+2);
        }
        if(f&&v[ans[1]-1]<v[i])
            ans[1] =i+1;
        if(v[i]>v[i+1]&&f){
            f = 2;
            ans.push_back(i + 2);
            break;
        }
    }
    if(f==2){
        cout << "YES" << endl;
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    }else cout<<"NO"<<endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}