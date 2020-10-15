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
int xl[110];
vector<vector<int>> aa;
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>xl[i];
    }
    int fr=1,bk=n;
    int head=1,tail=n;
    int flag=0;
    while(fr<bk){
        //cout<<"head="<<head<<' '<<"tail="<<tail<<' '<<"fr="<<fr<<' '<<"bk="<<bk<<endl;
        int thead=head,ttail=tail;
        tail=n-(thead-1);
        head=(n-ttail+1);
        vector<int> ans;
        ans.clear();
        for(int i=1;i<head;i++)
            ans.push_back(1);
        int fnd;
        if(flag){
            fnd=bk;
            bk--;
        }
        else {fnd=fr;fr++;}
        flag^=1;
        // cout<<"thistime="<<fnd<<endl;
        int lo;
        for(lo=head;lo<=tail;lo++)
            if(xl[lo]==fnd)
                break;
        if(lo!=head){
            //continue;
        if(lo-head)
        ans.push_back(lo-head);
        // cout<<"lo-head"<<lo-head<<endl;
        if(tail-lo+1)
        ans.push_back(tail-lo+1);
        for(int i=n;i>tail;i--)
            ans.push_back(1);
        reverse(xl+1,xl+n+1);
        int now=1;
        // cout<<"lo="<<lo<<endl;
        // cout<<"ans=";
        // for(int i=0;i<ans.size();i++)
        //     cout<<ans[i]<<' ';
        // cout<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            reverse(xl+now,xl+now+ans[i]);
            now+=ans[i];
        }
        // cout<<"xl=";
        // for(int i=1;i<=n;i++){
        //     cout<<xl[i]<<' ';
        // }
        // cout<<endl;
        aa.push_back(ans);
        }
        tail--;
    }
    if(n>1&&xl[1]>xl[2]){
        vector<int> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(1);
        aa.push_back(ans);
    }
    cout<<aa.size()<<endl;
    for(int i=0;i<aa.size();i++){
        cout<<aa[i].size()<<' ';
        for(int j=0;j<aa[i].size();j++){
            cout<<aa[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<xl[i]<<' ';
    }
    cout<<endl;
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