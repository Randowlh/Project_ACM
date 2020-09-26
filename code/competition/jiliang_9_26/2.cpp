#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
void work()
{
    vector<int> ans1,ans0;
    string a,b;
    cin>>a>>b;
    ans0.push_back(0);
    for(int i=0;i<b.size();i++){
        if(b[i]=='1'&&(i==0||b[i-1]=='0')){
            ans0.push_back(i+1);
        }
        if(b[i]=='0'&&i>0&&b[i-1]=='1'){
            ans0.push_back(i+1);
        }
    }
    int flag=0;
    for(int i=0;i<b.size();i++){
        if(b[i]!=a[i]&&flag)
            continue;
        if(b[i]==a[i]&&!flag)
            continue;
        ans1.push_back(i+1);
        flag^=1;
    }
    if(ans1.size()<ans0.size()){
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i]<<' ';
        }
        cout<<endl;
    }else{
        for(int i=0;i<ans0.size();i++){
            cout<<ans0[i]<<' ';
        }
        cout<<endl;
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}