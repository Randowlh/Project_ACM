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
struct seg{
    int T[410000<<2];
    inline void pushup(int pos){T[pos]=T[lson(pos)]+T[rson(pos)];}
    void update(int pos,int l,int r,int x){
        if(l==r){
            T[pos]++;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)
            update(lson(pos),l,mid,x);
        else update(rson(pos),mid+1,r,x);
        pushup(pos);
    }
    int query(int pos,int l,int r,int ql,int qr){
        if(l>=ql&&r<=qr)  
            return T[pos];
        int mid=l+r >> 1;
        int ans=0;
        if(ql<=mid)
            ans+=query(lson(pos),l,mid,ql,qr);
        if(qr>=mid+1)
            ans+=query(rson(pos),mid+1,r,ql,qr);
        return ans;
    }
}T;
int a[210000];
int date[410000];
map<int,int> M;
void work()
{
    int n,d,k;
    rd(n),rd(d),rd(k);
    for(int i=1;i<=n;i++)
        rd(a[i]);
    for(int i=1;i<=n;i++){
        date[i]=a[i]+i*d;
        date[n+i]=a[i]-i*d;
    }
    int tail=1;
    date[0]=llinf;
    sort(date+1,date+n*2+1);
    for(int i=1;i<=n*2;i++){
        if(date[i]!=date[i-1]){
            M[date[i]]=tail;
            tail++;
        }
    }
    for(int i=1;i<=n*2;i++)
        T.update(1,1,tail,M[date[i]]);
    for(int i=1;i<=n;i++){
        int now=
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