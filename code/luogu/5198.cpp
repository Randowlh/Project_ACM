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
char mp[1005][1005];
int date[1000050];
int sz[1000050];
int zc[1000050];
int b[][2]= {{1, 0}, {0, 1}, {0, -1},{-1, 0}};
int n;
int find(int x){
    if(date[x]==x)
        return x;
    else return date[x]=find(date[x]);
}
inline void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    date[l]=r;
}
bool ck(int x,int y)
{
    if(x<0 || x >= n)
    return false;
    if(y<0 || y >= n)
    return false;
    return mp[x][y]=='#';
}
bool ck2(int x,int y){
    if(x<0 || x >= n)
    return true;
    if(y<0 || y >= n)
    return true;
    return mp[x][y]=='.';
}
void work()
{
    set<int> s;
    //int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mp[i][j];
    for(int i=0;i<n*n;i++)
        date[i]=i;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(mp[i][j]=='.')
                continue;
            for(int k=0;k<4;k++){
                if(ck(i+b[k][0],j+b[k][1]))
                    merge(i*n+j,(i+b[k][0])*n+j+b[k][1]);
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mp[i][j]=='#'){
                sz[find(i*n+j)]++;
                int cnt=0;
                for(int k=0;k<4;k++)
                    if(ck2(i+ b[k][0], j + b[k][1]))
                        cnt++;
                zc[find(i*n+j)]+=cnt;
            }
    pair<int,int> ans(0,llinf);
    for(int i=0;i<n*n;i++){
        if(sz[i]==ans.first)  
            MIN(ans.second,zc[i]);
        if(sz[i]>ans.first)
            ans.first=sz[i],ans.second=zc[i];
    }
    cout<<ans.first<<' '<<ans.second<<endl;
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