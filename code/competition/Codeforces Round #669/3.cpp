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
int date[110000];
void work()
{
    int n;
    cin>>n;
    set<int> s,s1;
    for(int i=1;i<=n;i++)
        s.insert(i);
    s1=s;
    while(s.size()>1){
        int a=*s.begin();
        s.erase(s.begin());
        int b=*s.begin();
        s.erase(s.begin());
        int k1,k2;
        cout<<"? "<<a<<' '<<b<<endl;
        cin>>k1;
        cout<<"? "<<b<<' '<<a<<endl;
        cin>>k2;
        if(k2>k1){
            date[b]=k2;
            s1.erase(k2);
            s.insert(a);
        }else{
            date[a]=k1;
            s1.erase(k1);
            s.insert(b);
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        if(date[i])
            cout<<date[i]<<' ';
        else cout<<*s1.begin()<<' ';
    } 
    cout<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
  // freopen("in.txt","r",stdin);
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