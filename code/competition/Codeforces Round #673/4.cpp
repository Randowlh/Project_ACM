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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
const int maxn = 510000;
int date[11000];
struct node{
    int i,j,x;
    node(int a,int b,int c):i(a),j(b),x(c){}
};
void work()
{
    vector<node> ans;
    int n;
    cin>>n;
    int tol=0;
    for(int i=1;i<=n;i++){
        cin>>date[i];
        tol+=date[i];
    }
    if(tol%n){
        cout<<-1<<endl;
        return ;
    }
    for(int i=2;i<=n;i++){
        if(date[i]/i==0)
            continue;
        ans.push_back(node(i,1,date[i]/i));
        date[1]+=date[i]/i*i;
        date[i]%=i;
    }   
    yx_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=2;i<=n;i++){
        if(date[i])
            q.push(make_pair(i-date[i],i));
    }
    while(!q.empty()){
        pair<int,int>t=q.top();
        q.pop();
        if(date[1]<t.first){
            break;
        }
        ans.push_back(node(1,t.second,t.first));
        ans.push_back(node(t.second,1,1));
        date[1]+=date[t.second];
        date[t.second]=0;
    }
    for(int i=2;i<=n;i++){
        if(date[i]>tol/n){
            cout<<-1<<endl;
            return;
        }
        ans.push_back(node(1,i,tol/n-date[i]));
        date[1]-=(tol/n-date[i]);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].i<<' '<<ans[i].j<<' '<<ans[i].x<<endl;
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
cin>>t;
//cin>>t;
while (t--)
{
work();
}
return 0;
}