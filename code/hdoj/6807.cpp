#include <bits/stdc++.h>
#pragma GCC optimize(2)
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
template<class T>inline T& max(T &x,T &y){if(x<y)return y;else return x;}
template<class T>inline T& min(T &x,T &y){if(x<y)return x;else return y;}
template<class T>inline T& abs(T &x){if(x<0)return -x;else return x;}
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
double delta=0.999;
const int stemp=527;
#define MAX_TIME 940 
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
double l,r;
double mixx=999999999;
double mx=999999999;
double ans=0;
int h[501000],m[501000],s[501000];
double hh[501000],mm[501000],ss[501000];
double calc(double tt){
    double ans=0;
    double htt=tt/3600.0;
    double mtt=(tt-((int)htt)*3600)/60.0;
        int m1,m2;
        int l=0,r=n-1;
          while((r-l)>=99999){
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;
        if(max(ans,min(abs(mm[m1]-mtt),60-abs(mm[m1]-mtt))*6)>max(ans,min(abs(mm[m2]-mtt),60-abs(mm[m2]-mtt))*6))
            r=m2;
            else
             l=m1;
        }
        for(int i=l;i<=r;i++){
             MAX(ans,min(abs(mm[i]-mtt),60-abs(mm[i]-mtt))*6);
        }
        l=0,r=n-1;
          while((r-l)>=9999){
        m1=l+(r-l)/3;
        m2=r-(r-l)/3;
        if(max(ans,min(abs(hh[m1]-htt),12-abs(hh[m1]-htt))*30)>max(ans,min(abs(hh[m2]-htt),12-abs(hh[m2]-htt))*30))
            r=m2;
            else
             l=m1;
        }
        for(int i=l;i<=r;i++){
             MAX(ans,min(abs(hh[i]-htt),12-abs(hh[i]-htt))*30);
        }
    //}
    return ans;
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-12){
        double tnow=now+((rand()<<1)-RAND_MAX)*temp;
        if(tnow<l||tnow>r){
            temp*=delta;
            continue;
        }
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de<0){
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
    if(n>100)
        delta=0.999;  
    else
        delta=0.99;
     SA();
}
void work()
{
    ans=6*60*60;
    mx=99999999;
    rd(n);
    for(int i=0;i<n;i++)
       scanf("%d:%d:%d",&h[i],&m[i],&s[i]);
    l=0,r=12*3600;
    for(int i=0;i<n;i++)
        ss[i]=s[i],mm[i]=m[i]+s[i]/60.0,hh[i]=h[i]+mm[i]/60.0;
    sort(hh,hh+n);
    sort(mm,mm+n);
        repeat(1);
    printf("%.20f\n",mx);
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
    rd(t);
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}