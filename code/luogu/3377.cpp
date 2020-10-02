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
    int l,r,fa,val,dis;
}lt[110000];
int find(int x){
    if(lt[x].fa==x)
        return x;
    else return lt[x].fa=find(lt[x].fa);
}
int merge(int x,int y){
    if(!x||!y)  return x+y;
    if(lt[x].val>lt[y].val||(lt[x].val==lt[y].val&&x>y))
        swap(x,y);
    lt[x].r=merge(lt[x].r,y);
    lt[lt[x].r].fa=x;
    if(lt[lt[x].l].dis<lt[lt[x].r].dis)
        swap(lt[x].l,lt[x].r);
    lt[x].dis=lt[lt[x].r].dis+1;
    return x;
}
void pop(int x){
    lt[x].val=-1;
    lt[lt[x].l].fa=lt[x].l;
    lt[lt[x].r].fa=lt[x].r;
    lt[x].fa=merge(lt[x].l,lt[x].r);
}
void work()
{
    int n,m;
    cin>>n>>m;
    lt[0].dis=-1;
    for(int i=1;i<=n;i++)
        cin>>lt[i].val,lt[i].fa=i;
    int opt,x,y;
    for(int i=1;i<=m;i++){
        cin>>opt;
        if(opt==1){
            cin>>x>>y;
            if(lt[x].val==-1||lt[y].val==-1)
                continue;
            x=find(x);
            y=find(y);
            if(x==y)
                continue;
            lt[x].fa=lt[y].fa=merge(x,y);
        }else{
            cin>>x;
            if(lt[x].val==-1){
                cout<<-1<<endl;
                continue;
            }
            x=find(x);
            cout<<lt[x].val<<endl;
            pop(x);
        }
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// //std::ios::sync_with_stdio(false);
// //cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}