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
int lim=0;
int flag=0;
int ans[4][4]=
{{0,0,0,0},
 {0,1,2,3},
 {0,8,0,4},
 {0,7,6,5}};
int now[4][4];
int b[][2]={{1, 0}, {0, 1}, {0, -1},{-1, 0}};
bool ck(int x,int y){
    if(x<1||x>3)
        return false;
    if(y<1||y>3)
        return false;
    return true;
}
bool fuc(int step){
    int cnt=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(ans[i][j]^now[i][j])
                cnt++;
    return step+cnt<=lim;
}
bool judge(){
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(ans[i][j]^now[i][j])
                return false;
    return true;
}
void astar(int step,int x,int y,int pre){
    if(judge()){flag=1;return;}
    if(step==lim) return;
    for(int i=0;i<4;i++){
        if(pre+i==3)
            continue;
        if(!ck(x+b[i][0],y+b[i][1]))
            continue;
        swap(now[x][y],now[x+b[i][0]][y+b[i][1]]);
        if(fuc(step))astar(step+1,x+b[i][0],y+b[i][1],i);
        swap(now[x][y],now[x+b[i][0]][y+b[i][1]]);
        if(flag)
            return;
    }
}
void work()
{
    memset(now,0,sizeof(now));
    char a;
    int sx,sy;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            cin>>a;
            now[i][j]=a-'0';
            if(!now[i][j])
                sx=i,sy=j;
        }
    lim=0;
    if(judge()){
        cout<<0<<endl;
        return;
    }
    while(++lim){
        astar(0,sx,sy,-1);
        if(flag)
            break;
    }
    cout<<lim<<endl;
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