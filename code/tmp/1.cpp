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
class Solution {
public:
   int d[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    /**
     * @param inputQueries: input Queries, means [[m1, d1, m2, d2, x], [m1, d1, m2, d2, x],...]
     * @return: guess whether y1 is leep year
     */
    string guessYear(vector<vector<int>> &inputQueries) {
        // write your code here
        string ans;
        ans.clear();
         for(int i=0;i<inputQueries.size();i++){
            int m1,d1,m2,d2;
            m1=inputQueries[i][0]-1;
            d1=inputQueries[i][1];
            m2=inputQueries[i][2]-1;
            d2=inputQueries[i][3];
            int x=inputQueries[i][4];
            int tm1=m1,td1=d1;
            int cnt=0;
            int aa=0;
            while(tm1!=m2||td1!=d2){
             //  cout<<tm1<<' '<<td1<<' '<<m2<<' '<<d2<<endl;
               if(td1<d[0][tm1]){
                  td1++;
                  cnt++;
                  continue;
               }
               tm1++;
               tm1%=12;
               td1=1;
               cnt++;
               continue;
            }
            //cout<<"cnt="<<cnt<<' '<<"x="<<x<<endl;
            if(cnt==x&&m1<2){
               ans.push_back('P');
               continue;
            }
            cnt=0;
            tm1=m1,td1=d1;
            while(tm1!=m2||td1!=d2){
               if(td1<d[1][tm1]){
                 // cout<<tm1<<" "<<td1<<" "<<m2<<' '<<d2<<endl;
                  td1++;
                  cnt++;
                  continue;
               }
               //cout<<tm1<<" "<<td1<<" "<<m2<<' '<<d2<<endl;
               tm1++;
               tm1%=12;
               td1=1;
               cnt++;
               continue;
            }
            if(cnt==x){
               if(m1==m2)
                  ans.push_back('?');
               else 
            }
               ans.push_back('?');
         }
         return  ans;
    }
}a;
void work()
{
   int t = 4;
   int tmp;
   vector<vector<int>> tt;
   for(int i=1;i<=t;i++){
      vector<int> aa;
      for(int i=1;i<=5;i++){
         cin>>tmp;
         aa.push_back(tmp);
      }
      tt.push_back(aa);
   }
   cout<<a.guessYear(tt)<<endl;
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