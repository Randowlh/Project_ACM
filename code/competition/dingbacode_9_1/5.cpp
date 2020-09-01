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
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int date[110000];
int pre[110000];
int dp[110000];
inline int getval(int l,int r,int f){
   int ans=0;
   if(f){
      ans=(pre[r]-pre[l-1]>0);
      ans-=(pre[r]-pre[l-1]<0);
   }else{ 
      ans=(pre[r]-pre[l-1]<0);
      ans-=(pre[r]-pre[l-1]>0);
   }
   return  ans;
}
void work()
{
   int n,l,r;
   rd(n),rd(l),rd(r);   
   for(int i=1;i<=n;i++)
      rd(date[i]);
   if(l==1&&r==n){
      int ans1=0;
      int ans2=0;
      int f1=0,f2=0;
      int tl1=0,tl2=0;
      for(int i=1;i<=n;i++){
         if(!date[i])
         continue;
         if(date[i]<0){
            if(!f1)
            f1=i;
            tl1+=date[i];
            ans2++;
            if(f2){
               if(abs(date[f2-1])>abs(tl2))
                  ;
               else if(abs(date[i])>abs(tl2)){
                  date[i]=date[i]+tl2;
               }else ans2--;
               tl2=0;
               f2=0;
            }
         }else{
            if(!f2)
            f2=i;
            tl2+=date[i];
            ans1++;
            if(f1){
              if(abs(date[f1-1])>abs(tl1))
                  ;
               else if(abs(date[i])>abs(tl1)){
                  date[i]=date[i]+tl1;
               }else ans1--;
            tl1=0;
            f1=0;
            }
         }
      }
      if(f1)
      ans1--;
      if(f2)
      ans2--;
      cout<<ans1<<endl;
      cout<<ans2<<endl;
      return;
   }
   for(int i=1;i<=n;i++)
      pre[i]=pre[i-1]+date[i];
   for(int i=1;i<l;i++)
      dp[i]=-llinf;
  for(int i=l;i<=n;i++){
      dp[i]=-llinf;
      for(int j=max(i-r+1,1LL);j<=i-l+1;j++)
         MAX(dp[i],dp[j-1]+getval(j,i,1));
   }
   cout<<dp[n]<<endl;
   for(int i=l;i<=n;i++){
      dp[i]=-llinf;
      for(int j=max(i-r+1,1LL);j<=i-l+1;j++)
         MAX(dp[i],dp[j-1]+getval(j,i,0));
   }
   cout<<dp[n]<<endl;
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