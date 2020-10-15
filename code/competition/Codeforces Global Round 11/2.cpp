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
void work()
{
    int n,k;
    cin>>n>>k;
    string tmp;
    cin>>tmp;
    int ans=0;
    int pre=0;
    yx_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<tmp.length();i++){
        if(tmp[i]=='W'){
            int f=1;
            if(i-1>=0&&tmp[i-1]=='W')
                f++;
            ans+=f;
        }
    }
    int flag=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]=='W'){
            if(i-pre&&flag)
                q.push(i-pre);
            flag=1;
            pre=i+1;
        }
    }
    while(k&&!q.empty()){
        int t=q.top();
        q.pop();
        if(t<=k){
            k-=t;
            ans+=t*2+1;
        }else{
            ans+=k*2;
            k=0;
            break;
        }
    }
    if(k){
        int cnt=0;
        flag=0;
        for(int i=tmp.size()-1;i>=0;i--){
            if(tmp[i]=='W'){
                flag=1;
                break;
            }
            cnt++;
        }
        if(flag)
            for(int i=0;i<tmp.size();i++){
                if(tmp[i]=='W')
                    break;
                cnt++;
            }
        if(!flag){
            cout<<k*2-1<<endl;
            return;
        }
        ans+=min(k,cnt)*2;
    }
    cout<<ans<<endl;
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
cin>>t;
while (t--)
{
work();
}
return 0;
}