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
const int maxn = 150000;
int ans[maxn],date[maxn],bsz,now;
int cnt[(int)1e6+100];
struct qr{
    int l,r,t,num;
    inline bool operator<(qr a){
        if(l/bsz==a.l/bsz)
            if(r/bsz==a.r/bsz)
                return t<a.t;
            else return r<a.r;
        else return l<a.l;
    }
}q[maxn];
int tailq,tailc;
pair<int,int> cg[maxn];
inline void add(int x){
    if(!cnt[x])
        now++;
    cnt[x]++;
}
inline void sub(int x){
    cnt[x]--;
    if(!cnt[x])
        now--;
}
inline void modf(int i,int t){
    if(cg[t].first>=q[i].l&&cg[t].first<=q[i].r){
        sub(date[cg[t].first]);
        add(cg[t].second);
    }
    swap(cg[t].second,date[cg[t].first]);
}
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    char opt;
    int l,r;
    for(int i=1;i<=m;i++){
        cin>>opt>>l>>r;
        if(opt=='Q'){
            tailq++;
            q[tailq].l=l;
            q[tailq].r=r;
            q[tailq].t=tailc;q[tailq].num=tailq;
        }else{
            tailc++;
            cg[tailc].first=l,cg[tailc].second=r;
        }
    }
    bsz=pow(n,0.66666);
    sort(q+1,q+tailq+1);
    l=1,r=0;
    int tim=0;
    for(int i=1;i<=tailq;i++){
        while(l>q[i].l)
            add(date[--l]);
        while(r<q[i].r)
            add(date[++r]);
        while(l<q[i].l)
            sub(date[l++]);
        while(r>q[i].r)
            sub(date[r--]);
        while(tim<q[i].t)
            modf(i,++tim);
        while(tim>q[i].t)
            modf(i,tim--);
        ans[q[i].num]=now;
    }
    for(int i=1;i<=tailq;i++){
        cout<<ans[i]<<endl;
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