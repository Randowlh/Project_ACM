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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
void work()
{
    int t;
    rd(t);
    if(t==1||t==24){
        printf("Fake news!\n");
    }else printf("Nobody knows it better than me!\n");
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
   
    // int tmp=0;
    // int now=0;
    // for(int i=1;i<100000;i++){
    //     now=i*i;
    //     tmp+=now;
    //     for(int j=1;j*j<=tmp;j++)
    //     {
    //         if(j*j==tmp){
    //         cout<<i<<endl;
    //         cout<<"YES"<<endl;
    //         }
    //     }
    // }
     rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}