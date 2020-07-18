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
    string tmp;
    cin >> tmp;
    int a=0, b=0;
    int cnt = 0;
    int qa = 0;
    int flag=0;
    for (int i = 0;i<tmp.size();i++){
        if(tmp[i]=='a'){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt<0){
            cout << "Dead Fang" << endl;
            return;
        }
    }
    if(cnt==0){
        cout << "Happy Fang" << endl;
        return;
    }
    for (int i = tmp.size()-1; i >=0;i--){
        if(tmp[i]=='b')
        break;
        else
            cnt--;
    }
     if(cnt==0){
        cout << "Happy Fang" << endl;
        return;
    }else
        cout << "Sad Fang" << endl;

    //     Happy Fang
    // Sad Fang
    // Dead Fang

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