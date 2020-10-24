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
int mp[1100][1100];
int vis[1100][1100];
int b[][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;
struct node{
    int x,y;
    node(int a,int b):x(a),y(b){}
    bool operator<(node a)const{
        return x<a.x;
    }
};
bool ck(int x,int y){
    if(x<=0||x>n)
        return false;
    if(y<=0||y>n)
        return false;
    return !vis[x][y];
}
void work()
{
    //int n;
    rd(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            rd(mp[i][j]);
    yx_queue<pair<int,node>> q;
    vis[1][1]=llinf;
    q.push(make_pair(mp[1][1],node(1,1)));
    while(!q.empty()){
        int t=q.top().first;
        node lo=q.top().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(ck(lo.x+b[i][0], lo.y+b[i][1])){
                int x=lo.x+b[i][0],y=lo.y+b[i][1];
                q.push(make_pair(min(mp[x][y],t),node(x,y)));
                vis[x][y]=min(mp[x][y],t);
            }
        }
    }
    int k;
    rd(k);
    int tmp;
    for(int i=1;i<=k;i++){
        rd(tmp);
        if(tmp>vis[n][n]){
            cout<<"Hmmm"<<endl;
        }else cout<<"Wuhu"<<endl;
    }
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