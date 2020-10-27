#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int maxn = 5200;
vector<int> primes;
bool is_prime[10000100];
void euler()
{
   is_prime[1] = 1;
   for (int i = 2; i < maxn; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
int date[maxn];
int dp[maxn];
int n;
int dfs(int pos){
    if(dp[pos]!=-1)
        return dp[pos];
    int now=0;
    int ans=0;
    int t=1;
    while(true){
        t=lower_bound(date+t,date+n+2,primes[now]*date[pos])-date;
        if(date[t]==llinf)
            break;
        if(primes[now]*date[pos]==date[t]){
            MAX(ans,dfs(t));
            now++;
        }
        else{
            int dis=date[t]/date[pos]+(date[t]%date[pos]>0);
            now=lower_bound(primes.begin(),primes.end(),dis)-primes.begin();
        }
    }   
    ans++;
    dp[pos]=ans;
    return ans;
}
void work()
{
    rd(n); 
    euler();
    for(int i=1;i<=n;i++)
        rd(date[i]),dp[i]=-1;
    sort(date+1,date+n+1);
    n=unique(date+1,date+n+1)-date-1;
    date[n+1]=llinf;
    int aa=0;
    for(int i=1;i<=n;i++)
        MAX(aa,dfs(i));
    cout<<aa<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
    //freopen("tt.txt","w",stdout);
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