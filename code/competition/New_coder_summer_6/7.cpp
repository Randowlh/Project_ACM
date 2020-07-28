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
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int  dp[110][2000][2][2];
int disg[110];
int dfs(int pos,int staus,int flag,int flag2){
    if(staus+(pos-1+flag2)*9<0)
        return 0;
    if(!pos)
    return staus>0; 
 //   cout<<pos<<" "<<staus<<endl;
    if(dp[pos][staus+1000][flag][flag2]!=-1)
    return dp[pos][staus+1000][flag][flag2];
    int num=flag?9:disg[pos];
    int ans=0;
    for(int i=0;i<=num;i++){
        for(int j=0;j<=(flag2?9:i);j++){
            ans+=dfs(pos-1,staus-i+j,flag||i<num,flag2||j<i);
            ans%=mod;
        }
    }
    dp[pos][staus+1000][flag][flag2]=ans;
    return ans;
}
void work()
{
    memset(dp,-1,sizeof(dp));
    string n;
    cin>>n;
    reverse(n.begin(),n.end()); 
    for(int i=0;i<n.length();i++){
        disg[i+1]=n[i]-'0';
    }
    cout<<dfs(n.size(),0,0,0)%mod<<endl;
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