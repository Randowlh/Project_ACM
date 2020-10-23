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
struct node{
    int val;
    int pre,nxt;
}date[210000];
set<pair<int,int>> s;
void work()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>date[i].val;
        s.insert(make_pair(date[i].val,i));
    }
    for(int i=0;i<n;i++){
        date[i].pre=(i-1+n)%n;
        date[i].nxt=(i+1)%n;
    }
    while(s.size()>3){
        int lo=s.begin()->second;
        s.erase(s.begin());
        int v=date[date[lo].nxt].val+date[date[lo].pre].val;
        date[lo].val=v;
        s.erase(s.find(make_pair(date[date[lo].pre].val,date[lo].pre)));
        s.erase(s.find(make_pair(date[date[lo].nxt].val,date[lo].nxt)));
        date[date[date[lo].nxt].nxt].pre=lo;
        date[date[date[lo].pre].pre].nxt=lo;
        date[lo].nxt=date[date[lo].nxt].nxt;
        date[lo].pre=date[date[lo].pre].pre;
        s.insert(make_pair(date[lo].val,lo));
    }
    int tol=0;
    for(auto i=s.begin();i!=s.end();i++)
        tol+=i->first;
    tol-=s.begin()->first;
    cout<<tol<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}