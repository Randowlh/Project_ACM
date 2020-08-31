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
struct node{
    int l,r;
    node(){l=-1,r=-1;}
}date[110000];
int exs[110000];
void work()
{
    int n;
    rd(n);
    int k,p;
    for(int i=2;i<=n;i++){
        rd(k),rd(p);
        if(p==0){
            int t=date[k].l;
            date[k].l=i;
            date[i].r=k;
            date[i].l=t;
            if(t!=-1)
                date[t].r=i;
        }else{
            int t=date[k].r;
            date[k].r=i;
            date[i].l=k;
            date[i].r=t;
            if(t!=-1)
                date[t].l=i;
        }
    }
    int m;
    rd(m);
    int tmp;
    for(int i=0;i<m;i++){
        rd(tmp);
        exs[tmp]=1;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        if(date[i].l==-1){
            now=i;
            break;
        }
    }
    
    while(now!=-1){
        if(!exs[now]){
            wt(now);
            putchar(' ');
        }
        now=date[now].r;
    }
    putchar('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}