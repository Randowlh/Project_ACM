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
const ll llinf = 4223372036854775807;
const ll mod = llinf;
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int n;
struct node
{
    // int n;
    int date[100][100];
    node operator*(node a)
    {
        node x;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int ans = 0;
                for (int k = 1; k <= n; k++)
                {
                    ans = ans + date[i][k] * a.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                date[i][j] = a.date[i][j];
        return *this;
    }   
} a,b,c;
void work()
{
    int cnt=0;
    int n1,m1,n2,m2;
    while(cin>>n1>>m1>>n2>>m2,n1||m1||n2||m2){
        cnt++;
        cout<<"Case #"<<cnt<<":"<<endl;
        n=max(n1,max(m1,max(m2,n2)));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                a.date[i][j]=0;
                b.date[i][j]=0;
            }
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=m1;j++)
                cin>>a.date[i][j];
        for(int i=1;i<=n2;i++)
            for(int j=1;j<=m2;j++)
                cin>>b.date[i][j];
        c=a*b;
        if(m1!=n2){
            cout<<"undefined"<<endl;
            continue;
        }
        for(int i=1;i<=n1;i++){
            cout<<"| ";
            for(int j=1;j<=m2;j++)
                cout<<c.date[i][j]<<' ';
            cout<<'|'<<endl;
        }
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