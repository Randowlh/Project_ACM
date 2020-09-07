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
struct node{
    int  T[5];
    int    sz;
    inline bool operator<(const node a)const {
        if(sz!=a.sz)
            return sz < a.sz;
        for(int i=0;i<5;i++)
            if(T[i]!=a.T[i])
                return T[i]<a.T[i];
        return false;
    }
};
map<node,int> M;
vector<vector<int>> v2,v3;
void work()
{
    int n;
    rd(n);
    int a[5];
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++)
            rd(a[j]);
        sort(a,a+5);
        for(int j=1;j<(1<<5);j++){
            int t=j;
            node tt;
            int cnt=0,tail=0;
            while(t){
                if(t&1){
                    tt.T[tail]=a[cnt];
                    tail++;
                }
                cnt++;
                t>>=1;
            }
            for(int j=tail;j<5;j++)
                tt.T[j]=0;
            tt.sz=tail;
            M[tt]++;
        }
    }
    int ans=0;
    for(auto i=M.begin();i!=M.end();i++){
        pair<node,int> t=*i;
        int j=t.second*(t.second-1)/2;
        if(t.first.sz%2==0){
            ans-=j;
        }else{
            ans+=j;
        }
    }
    cout<<n*(n-1)/2-ans<<endl;;
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