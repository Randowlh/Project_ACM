#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
void work()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<2<<endl;
        cout<<1<<' '<<2<<endl;
        return;
    }
    cout<<2<<endl;
    multiset<int> ji,ou;
    for(int i=1;i<=n;i++)
        if(i&1)
            ji.insert(i);
        else ou.insert(i);
    int cnt=n;
    while(cnt>1){
        if(!ji.empty()&&(ou.empty()||*ji.rbegin()>*ou.rbegin())){
            auto a=ji.rbegin();
            int t1=*a;
            a--;
            int t2=*a;
            cnt--;
            cout<<t1<<' '<<t2<<endl;
            ji.erase(t1),ji.erase(t2);
            if(ou.count((t1+t2)/2)){
                cnt--;
                cout<<(t1+t2)/2<<' '<<(t1+t2)/2<<endl;
            }else ou.insert((t1+t2)/2);
        }else{
            auto a=ou.rbegin();
            int t1=*a;
            a--;
            int t2=*a;
            cnt--;
            ou.erase(t1),ou.erase(t2);
            cout<<t1<<' '<<t2<<endl;
            if(ji.count((t1+t2)/2)){
                cnt--;
                cout<<(t1+t2)/2<<' '<<(t1+t2)/2<<endl;
            }else ji.insert((t1+t2)/2);
        }
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