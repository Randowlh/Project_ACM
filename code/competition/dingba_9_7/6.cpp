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
string a[2];
string ans;
void calc(string& in){
    int now=0;
    int cheng=1;
    while(!in.empty()){
        if(in[in.size()-1]=='1'){
            now+=cheng;
        }
        in.pop_back();
        cheng*=2;
    }
    now++;
    int aa=0;
    ans.clear();
    cout<<now<<endl;
    for(int i=0;now>(1<<i);i++){
        aa=(1<<(i+1));
    }
    for(int i=1;i<now;i++)
        ans.push_back('0');
    ans.push_back('1');
    while(ans.size()<aa)
        ans.push_back('0');
    reverse(ans.begin(),ans.end());
    //cout<<ans<<endl;
}
void work()
{
    int n,q;
    cin>>n>>q;
    cin>>a[0];
    int l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        string tmp=a[0].substr(l-1,r-l+1);
        calc(tmp);
        string&tt=ans;
        a[1].clear();
        for(int i=0;i<l-1;i++){
            a[1].push_back(a[0][i]);
        }
        a[1]+=tt;
        for(int i=r;i<a[0].size();i++){
            a[1].push_back(a[0][i]);
        }
        a[0]=a[1];
    }
    vector<int> aa;
    for(int i=0;i<a[0].size();i++){
        if(a[0][i]=='1')
            aa.push_back(i+1);
    }
    cout<<aa.size()<<endl;
    for(int i=0;i<aa.size();i++){
        cout<<aa[i]<<' ';
    }
    cout<<endl;
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