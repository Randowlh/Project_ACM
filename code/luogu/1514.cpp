#include<bits/stdc++.h>
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
const ll mod = (0 ? 1000000007 : 998244353);
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)

const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int b[][2]={{1, 0}, {0, 1},{0, -1},{-1, 0}};
pair<int,int> seg[510];
int date[510][510];
int book[510][510];
int n,m;
bool ck(int x,int y,int s){
    if(x<=0&&x>n)
    return false;
    if(y<=0&&y>m)
    return false;
    return book[x][y]!=s;
}
bool bfs(int s){
    int f=0;
    queue<pair<int,int>> q;
    book[n][s]=s;
    q.push(make_pair(n,s));
    while(!q.empty()){
        pair<int,int> t=q.front();
        q.pop();
        if(t.first==1){
            MIN(seg[s].first,t.second);
            MAX(seg[s].second,t.second);
            f=1;
        }
        for(int i=0;i<4;i++)
        if(ck(t.first+b[i][0],t.second+b[i][1],s)&&date[t.first][t.second]<date[t.first+b[i][0]][t.second+b[i][1]]){
            q.push(make_pair(t.first+b[i][0],t.second+b[i][1]));
            book[t.first+b[i][0]][t.second+b[i][1]]=s;
        }
    }
    return f>0;
}
void work()
{
    rd(n),rd(m);
    for(int i=1;i<=n;i++){  
        for(int j=1;j<=m;j++)
            rd(date[i][j]),book[i][j]=0;
    }
    if(n==1){
        if(m==1){
        printf("1\n1\n");
        return;
        }
        printf("1\n");
        int ans=0;
        for(int i=2;i<=m-1;i++){ 
            if(date[1][i]>=date[1][i-1]&&date[1][i]>=date[1][i+1]){
                ans++;
            }
        }
        if(date[1][1]>=date[1][2])
        ans++;
        if(date[1][m]>=date[1][m-1])
        ans++;
        printf("%lld\n",ans);
        return;
    }
    for(int i=1;i<=m;i++)
     seg[i].first =llinf,seg[i].second=-llinf;
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(!bfs(i))
            cnt++;
    }
    if(cnt){
        printf("0\n");
        printf("%lld\n",cnt);
        return;
    }
    printf("1\n");
    sort(seg+1,seg+m+1);
    int next=0;
    int ans=0;
    // for(int i=1;i<=m;i++){
    //     cout<<"seg[i].first="<<seg[i].first<<' '<<seg[i].second<<endl;
    // }
    for(int i=1;i<=m;i++){
        // cout<<seg[i].first<<" ? "<<seg[i].second<<endl;
        if(seg[i].first<=next&&seg[i].second>=next){
           
            continue;
        }
        ans++;
         next = seg[i].second;
      //  cout<<next<<' '<<ans<<endl;
    }
    printf("%lld\n",ans);
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
    //cin>
    while (t--)
    {
        work();
    }
    return 0;
}