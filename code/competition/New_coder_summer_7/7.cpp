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
const int maxn = 510000;
#define int long long
const double delta=0.999999;
const int stemp=5000;
#define MAX_TIME 940 
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
double l,r;
int mx=-999999999;
int re;
double ans=0;
pair<int,int> date[1000];
int calc(double a){
    a=a-(int)a;
    for(int i=0;i<n;i++){
         a*=re*2;
        date[i].first=(int)a/re*2;
        date[i].first%=re*2;
        date[i].first-=re;
          a*=re*2;
        date[i].second=(int)a/re*2;
        date[i].second%=re*2;
        date[i].second-=re;
    }
    // for(int i=0;i<n;i++){
    //     if(date[i].first*date[i].first+date[i].second*date[i].second>re*re)
    //     return 0;
    // }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=(date[i].first-date[j].first)*(date[i].first-date[j].first)+(date[i].second-date[j].second)*(date[i].second-date[j].second);
        }
    }
   // exit(0);
    return ans;
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-14){
        double tnow=now+((rand()<<1)-RAND_MAX)*temp;
       // cout<<temp<<endl;
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de>0){
            now=tnow;
            ans=tnow;
            mx=new_ans;
        }else if(exp(-de/temp)*RAND_MAX>rand()){
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
    for(n=2;n<=8;n++){
        for(re=1;re<=31;re++){
            r=re;
            mx=0;
            ans=0;
            repeat(1);
            cout<<mx/2<<',';
        }
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
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