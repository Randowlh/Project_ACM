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
int date[11000];
int lk[11000];
int find(int x){ 
    if(lk[x]^x){
        return lk[x]=find(lk[x]);
    }else return x;
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    lk[l]=r;
}
inline int get1(int x){
    int ans=0;
    while(x){
        if(x&1)
            ans++;
        x>>=1;
    }
    return ans;
}
void work()
{
    int n;
    rd(n);
    for(int i=1;i<=n;i++)
        rd(date[i]),lk[i]=i;
    vector<pair<int,pair<int,int>>>eg;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            eg.push_back(make_pair(get1(date[i]^date[j]),make_pair(i,j)));
        }
    sort(eg.begin(),eg.end());
    for(int i=0;i<eg.size();i++){
        if(find(eg[i].second.first)^find(eg[i].second.second)){
            ans+=eg[i].first;
            merge(eg[i].second.second,eg[i].second.first);
        }
    }   
    cout<<ans<<endl;
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