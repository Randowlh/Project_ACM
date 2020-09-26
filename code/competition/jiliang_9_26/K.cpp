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
int mth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
bool run(int y){
    if(y%400==0)
        return true;
    if(y%100==0)
        return false;
    if(y%4==0)
        return true;
    return false;
}
inline bool ck(string tmp){
    if(tmp.size()<8){
        return false;
    }
    for(int i=0;i<8;i++){
        if(tmp[i]==' ')
            return false;
        tmp[i]-='0';
    }
    for(int i=0;i<4;i++){
        if(tmp[i]^tmp[7-i]){
            return false;
        }
    }
    int year=0;
    int mo=0;
    int dy=0;
    year=tmp[0]*1000+tmp[1]*100+tmp[2]*10+tmp[3];
    mo=tmp[4]*10+tmp[5];
    dy=tmp[6]*10+tmp[7];
    if(mo<1||mo>12)
        return false;
    if(dy<1)
        return false;
    int t=run(year);
    if(dy<=mth[t][mo]&&dy>0){
        return  true;
    }
    return false;
}
void work()
{
    string tmp;
    while(true){
        getline(cin,tmp);
        if(tmp=="#")
            break;
        int ans=0;
        for(int i=0;i<tmp.size();i++){
            if(ck(tmp.substr(i,8)))
                ans++;
        }
        cout<<ans<<endl;
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}