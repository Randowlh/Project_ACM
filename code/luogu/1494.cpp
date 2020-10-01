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
inline int gcd(int a,int b){ return b ? gcd(b, a % b) : a;}
int date[51000];
pair<int,int> ans[51000];
int cnt[51000];
int fz,fm,len;
int bsz;
struct qr{
    int l,r,num;
    inline bool operator<(qr a){
        if(l/bsz==a.l/bsz)
            return r<a.r;
        return l<a.l;
    }
    inline bool operator>(qr a){
        return num<a.num;
    }
    qr(int a=0,int b=0,int n=0): l(a),r(b),num(n){}
};
void add(int x){
    fz+=cnt[date[x]];
    cnt[date[x]]++;
    fm+=len;
    len++;
}
void del(int x){
    cnt[date[x]]--;
    fz-=cnt[date[x]];
    len--;
    fm-=len;
}
void work()
{
    len=fz=fm=0;
    int n,m;
    rd(n),rd(m);
    bsz=sqrt(n);
    for(int i=1;i<=n;i++)
        rd(date[i]);
    int l,r;
    vector<qr> q;
    for(int i=1;i<=m;i++){
        rd(l),rd(r);
        q.push_back(qr(l,r,i));
    }
    sort(q.begin(),q.end());
    l=1;r=0;
    for(int i=0;i<q.size();i++){
        while(l>q[i].l)
            add(--l);
        while(r<q[i].r)
            add(++r);
        while(l<q[i].l)
            del(l++);
        while(r>q[i].r)
            del(r--);
        ans[q[i].num]=MP(fz,fm);
    }
    for(int i=1;i<=m;i++){
        if(ans[i].first==0){
            printf("0/1\n");
            continue;
        }
        int t=gcd(ans[i].first,ans[i].second);
        printf("%lld/%lld\n",ans[i].first/t,ans[i].second/t);
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