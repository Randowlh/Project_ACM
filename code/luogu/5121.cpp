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
int n,k;
int date[11000];
int cnt[11000];
char mp[120][20];
int flag[120][20];
int find(int x){
    if(date[x]^x)
        return  date[x]=find(date[x]);
    else return  x;
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l!=r){
        cnt[r]+=cnt[l];
        date[l]=r;
    }
}
int b[][2]={{1, 0}, {0, 1}, {0, -1},{-1, 0}};
bool ck(int x,int y,char cl){
    if(x<=0||x>n)
        return false;
    if(y<=0||y>10)
        return false;
    return mp[x][y]==cl;
}
void work()
{  
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=10;j++)
            cin>>mp[i][j];
    while(true){
        int f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=10;j++){
                date[i*10+j]=i*10+j;
                cnt[i*10+j]=1;
                flag[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=10;j++)
                for(int k=0;k<4;k++)
                    if(ck(i+b[k][0],j+b[k][1],mp[i][j]))
                        merge(i*10+j,(i+b[k][0])*10+j+b[k][1]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=10;j++)
                if(cnt[find(i*10+j)]>=k&&mp[i][j]!='0')
                    flag[i][j]=1,f=1;
        for(int j=1;j<=10;j++){
            vector<char> tmp;
            for(int i=n;i>=1;i--){
                if(!flag[i][j]&&mp[i][j]!='0')
                    tmp.push_back(mp[i][j]);
            }
            for(int i=n;i>n-tmp.size();i--)
                mp[i][j]=tmp[n-i];
            for(int i=n-tmp.size();i>=1;i--)
                mp[i][j]='0';
        }
        if(!f)
            break;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++)
            cout<<mp[i][j];
        cout<<endl;
    }
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