#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
// #define double ld
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const ll mod = (1 ? 1e18 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int maxn = 510000;
#define int long long
const double delta=0.999999;
const int stemp=1283;
#define MAX_TIME 940 
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
std::mt19937 myrand(time(0));
int n;
double l,r;
int mx=-999999999;
int re;
double ans=0;
pair<int,int> date[1000], t[1000];
int tail=0;
int calc(double a){
    a=abs(a);
    int tt=powmod(tail,n);
    while(a<tt){
        a*=tail;
    }
    int tta=(int)a;
    for(int i=0;i<n;i++){
        t[i]=date[tta%tail];
        tta/=tail;
    }
    int ans=0;  
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ 
            ans+=(t[i].first-t[j].first)*(t[i].first-t[j].first)+(t[i].second-t[j].second)*(t[i].second-t[j].second);
        }
    }
    return ans;
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-7){
        double tnow=now+((myrand()<<1)-RAND_MAX)*temp;
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de>0){
            now=tnow;
            ans=tnow;
            mx=new_ans;
        }else if(exp(-de/temp)*RAND_MAX>myrand()){
            now=tnow;
        }
        temp*=delta;
    }
}
void repeat(double t){
        SA();
}
void work()
{
     l=0;
    n=8;
        cout<<"{";
        for(re=1;re<=30;re++){
            tail=0;
            mx=0;
            for(int k=-re;k<=re;k++){
                date[tail].first=k;
                date[tail++].second=(int)sqrt(re*re-k*k);
                date[tail].first=k;
                date[tail++].second=-date[tail-1].second;
            }
            sort(date,date+tail);
            ans=0;
            SA();
            cout<<mx;
            if(re!=30)
            cout<<',';
        }
        cout<<"},\n";
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
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