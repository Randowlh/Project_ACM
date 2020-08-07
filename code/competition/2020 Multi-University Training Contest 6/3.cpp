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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
const int maxm= 1;
struct Edges{
    int w,to,next;
}edge[maxm];
int head[maxm];
int ecnt=0;
void add(int u,int v,int w){
    edge[++ecnt].next=head[u];
    edge[ecnt].to=v;
    edge[ecnt].w=w;
    head[u]=ecnt;
}
set<char> s;
map<char,int> M; 
void work()
{
    string tmp;
    while(cin>>tmp){
    int f=0;
    int ma=2;
    for(int i=0;i<tmp.size();i++){
        if(!s.count(tmp[i])){
            cout<<"-1"<<endl;
            f=1;
            break;
        }
        if(M.count(tmp[i]))
        ma=max(ma,M[tmp[i]]+1);
    }
    if(f)continue;
    for(int r=ma;r<=16;r++){
        int a[3];
        memset(a, 0, sizeof(a));
        char opt=0;
        int flag=0;
        for(int i=0;i<tmp.size();i++){
            if(M.count(tmp[i])){
                a[flag]*=r;
                a[flag]+=M[tmp[i]];
                continue;
            }
            if(flag==0){
                opt=tmp[i];
                flag++;
                continue;
            }
            flag++;
        }
        if(opt=='+'||opt=='-'){
            if(opt=='-')
            a[1]= -a[1];
            if(a[0]+a[1]==a[2]){
                cout<<r<<endl;
                f=1;
                break;
            }
            continue;
        }
        if(opt=='/'){
            if(a[0]%a[1]==0&&a[0]/a[1]==a[2]){
                cout<<r<<endl;
                f=1;
                break;
            }
            continue;
        }
        if(opt=='*'){
            if(a[0]*a[1]==a[2]){
                cout<<r<<endl;
                f=1;
                break;
            }
            continue;
        }
    }
        if(f)continue;
        cout<<-1<<endl;
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
    //rd(t);
    for(int i='A';i<='Z';i++)
        M[i]=10+i-'A';
    for(int i='A';i<='F';i++)
        s.insert(i);
    for(int i=0;i<10;i++)
        M[i+'0']=i,s.insert(i+'0');
    s.insert('=');
    s.insert('/');
    s.insert('*');
    s.insert('+');
    s.insert('-');
    while (t--)
    {
        work();
    }
    return 0;
}