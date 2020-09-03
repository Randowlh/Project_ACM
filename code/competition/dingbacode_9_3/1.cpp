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
const int K=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
stack<int> tmp;
int ans=llinf;
int n;
string arr;
void dfs(int step,int ci){
    if(step==n){
        if(tmp.empty()){
            ans=min(ci,ans);
        }
        return;
    }
    if(!tmp.empty()&&tmp.top()==arr[step]){
        int  cnt=1;
        while(!tmp.empty()&&tmp.top()==arr[step]){
            tmp.pop();
            cnt++;
        }
        if(cnt>=3){
            dfs(step+1,ci+1);
        }
        for(int i=0;i<cnt-1;i++)
            tmp.push(arr[step]);
    }
    tmp.push(arr[step]);
    dfs(step+1,ci);
    tmp.pop();
}
void work()
{
    cin>>n;    
    cin>>arr;
    dfs(0,0);
    if(ans==llinf)
        cout<<"No"<<endl;
    else cout<<"Yes"<<endl<<ans<<endl;
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