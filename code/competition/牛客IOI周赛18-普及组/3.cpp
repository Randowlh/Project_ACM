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
int date[1005][1005];
int aa[1100000];
int vis[1005][1005];
int tail=0;
int tag=0;
int n,m,sx,sy,d,x;
int b[][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
inline bool ck(int x,int y){
    if(x<0||x>=n)
        return false;
    if(y<0||y>=m)
        return false;
    return vis[x][y]!=tag&&date[x][y]!=-1;
}
struct node{
    int x,y;
    node(int a,int b):x(a),y(b){}
};
void work()
{
    tail=0;
    tag++;
    rd(n),rd(m),rd(sx),rd(sy),rd(d),rd(x);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            rd(date[i][j]);
    sx--;sy--;
    if(!ck(sx,sy)){
        printf("no\n");
        return;
    }
    queue<pair<node,int>> q;
    vis[sx][sy]=tag;
    q.push(make_pair(node(sx,sy),0));
    while(!q.empty()){
        pair<node,int> t=q.front();
        if(date[t.first.x][t.first.y]){
            aa[tail]=date[t.first.x][t.first.y];
            tail++;
        }
        q.pop();
        if(t.second>=d)
            continue;
        for(int i=0;i<4;i++)
            if(ck(t.first.x+b[i][0],t.first.y+b[i][1])){
                vis[t.first.x + b[i][0]][t.first.y + b[i][1]]=tag;
                q.push(make_pair(node(t.first.x+b[i][0],t.first.y+b[i][1]),t.second+1));
            }
    }
    sort(aa,aa+tail);
    tail=unique(aa,aa+tail)-aa;
    if(tail>=x){
    int ans=llinf;
    for(int i=0;i+x-1<tail;i++){
        MIN(ans,aa[i+x-1]-aa[i]);
    }
    printf("%lld\n",ans);
    }else printf("no\n");
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
rd(t);
//cin>>t;
while (t--)
{
work();
}
return 0;
}