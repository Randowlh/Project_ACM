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
int pre[2];
void work()
{
   int n,k;
   cin>>n>>k;
   string tmp;
   cin>>tmp;
   int ans=0;
   tmp="f"+tmp;
   queue<int> q;
   if(n%2){
      if(tmp[1]=='1'&&tmp[n]=='0'){
         cout<<"NO"<<endl;
         return;
      }
      if(tmp[1]=='0'&&tmp[n]=='1'){
         cout<<"NO"<<endl;
         return;
      }
   }
   if(k%2){
      cout<<"NO"<<endl;
      return;
   }
   for(int i=1;i<=k;i++){
      if(tmp[i]=='0')
         pre[0]++;
      else if(tmp[i]=='1')
         pre[1]++;
      else q.push(i);
   }
   while(pre[0]>pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[1]++;
      tmp[q.front()]='1';
      q.pop();
   }
   while(pre[0]<pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[0]++;
      tmp[q.front()]='0';
      q.pop();
   }
   for(int i=k+1;i<=n;i++){
      if(tmp[i]=='1')
         pre[1]++;
      if(tmp[i]=='0')
         pre[0]++;
      if(tmp[i]=='?')
         q.push(i);
      if(tmp[i-k]=='1')
         pre[1]--;
      if(tmp[i-k]=='0')
         pre[0]--;
      if(tmp[i-k]=='?')
         q.pop();
       while(pre[0]>pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[1]++;
      tmp[q.front()]='1';
      q.pop();
      }
      while(pre[0]<pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[0]++;
      tmp[q.front()]='0';
      q.pop();
      }
   }
   pre[0]=pre[1]=0;
   while(!q.empty())
      q.pop();
   for(int i=1;i<=k;i++){
      if(tmp[i]=='0')
         pre[0]++;
      else if(tmp[i]=='1')
         pre[1]++;
      else q.push(i);
   }
   while(pre[0]>pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[1]++;
      tmp[q.front()]='1';
      q.pop();
   }
   while(pre[0]<pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[0]++;
      tmp[q.front()]='0';
      q.pop();
   }
   for(int i=k+1;i<=n;i++){
      if(tmp[i]=='1')
         pre[1]++;
      if(tmp[i]=='0')
         pre[0]++;
      if(tmp[i]=='?')
         q.push(i);
      if(tmp[i-k]=='1')
         pre[1]--;
      if(tmp[i-k]=='0')
         pre[0]--;
      if(tmp[i-k]=='?')
         q.pop();
       while(pre[0]>pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[1]++;
      tmp[q.front()]='1';
      q.pop();
      }
      while(pre[0]<pre[1]){
      if(q.empty()){
         cout<<"NO"<<endl;
         return;
      }
      pre[0]++;
      tmp[q.front()]='0';
      q.pop();
      }
   }
   cout<<"YES"<<endl;
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
cin>>t;
//cin>>t;
while (t--)
{
work();
}
return 0;
}