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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
const double delta=0.993;//退火常数，越接近1越优
const int stemp=50;//初始温度
#define MAX_TIME 940 
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
double l,r;
double mx=-999999999;
double ans=0;
double date[10100];
double calc(double a){//函数计算函数
    double ans=0,now=1;
    for(int i=0;i<=n;i++)
        ans+=date[i]*now,now*=a;
    return ans;
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-14){
        double tnow=now+((rand()<<1)-RAND_MAX)*temp;
        if(tnow<l||tnow>r){
            temp*=delta;
            continue;
        }
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de>0){//如果当前的解更优，如果求最小值应该写de<0
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
    while((double)clock()/CLOCKS_PER_SEC<t){
        SA();
    }
}
void work()
{
    cin>>n;
    cin>>l>>r;
    for(int i=0;i<=n;i++){
        cin>>date[i];
    }
    reverse(date,date+n+1);
    repeat(0.093);//卡时限用执行 0.093ms
    printf("%.5f\n",ans);
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