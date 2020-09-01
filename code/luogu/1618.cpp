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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
void work()
{
    int a,b,c;
    rd(a),rd(b),rd(c);
    int f=0;
    for(int i=100;i<1000;i++){
        if(i%a)
            continue;
        int j=i/a*b,k=i/a*c;
        if(j>=1000)
        continue;
        if(k>=1000)
        continue;
        set<int> s;
        int t=i;
        while(t)
        s.insert(t%10),t/=10;
        while(j)
        s.insert(j%10),j/=10;
        while(k)
        s.insert(k%10),k/=10;
        if(s.count(0))
        continue;
        if(s.size()!=9)
        continue;
        wt(i),putchar(' '),wt(i/a*b),putchar(' '),wt(i/a*c),putchar('\n');
        f=1;
    }
    if(!f)
        printf("No!!!\n");
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