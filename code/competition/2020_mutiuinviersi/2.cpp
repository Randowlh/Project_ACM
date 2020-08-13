#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define rep(i,a,n) for(register int i=a;i<=n;++i)
#define per(i,a,n) for(register int i=n;i>=a;--i)
#define mst(x) memset(x,0,sizeof(x));
#define yx_queue priority_queue
#define PI acos(-1)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
typedef long long ll;
const ll mod=( 1 ?998244353:1000000007);
const int N=2;
const int inf=1<<30;
const ll llf=9e18;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int f[200100];
int find(int x){ return x==f[x] ? x : f[x] = find(f[x]); }
int min(int a,int b){if(a>b)return b;else return a;}
int max(int a,int b){if(a<b)return b;else return a;}
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
//while(rp++)
struct node{
    int zi,mu;
};
int biao[][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool ck(int x,int y){
    return gcd(x,y)!=1;
}
int tail=0;
vector<int> mp[110000];
pair<int,int> pnt[110000];
map<pair<int,int>,int> M; 
void work()
{
    M.clear();
    tail=0;
    int x,y;
    cin>>x>>y;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    int f=0;
    pair<int,int> t=q.front();
    tail++;
    M.insert(make_pair(t,tail));
    pnt[tail]=t;
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        if(t.first==t.second){
            f=1;
            break;
        }
        for(int i=0;i<8;i++){
            if(ck(t.first+biao[i][0],t.second+biao[i][1])){
                pair<int,int> to=make_pair(t.first+biao[i][0],t.second+biao[i][1]);
                if(!M.count(to)){         
                q.push(to);
                tail++;
                M.insert(make_pair(to,tail));
                pnt[tail]=to;
                }
            }
        }
    }
    for(int i=0;i<=tail+100;i++)
        mp[i].clear();
    if(f){
        printf("0/1\n");
        return;
    }
    for(int i=1;i<=tail;i++){
        for(int j=0;j<8;j++){
            pair<int,int> ta=make_pair(pnt[i].first+biao[j][0],pnt[i].second+biao[j][1]);
            if(M.count(ta)){
                mp[i].push_back(M[ta]);
            }
        }
        mp[i].push_back(i);
    }
    node ans;
    ans.mu=0;
    int tta=M[make_pair(x,y)];
    ans.zi=mp[tta].size();
    for(int i=1;i<=tail;i++){
        ans.mu+=mp[i].size();
    }
    int tt=gcd(ans.zi,ans.mu);
    //int tt=1;
   cout<<ans.zi<<'/'<<ans.mu<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int T = 1;
    rd(T);
    //cin>>t;
    while (T--)
    {
        work();
    }
    return 0;
}