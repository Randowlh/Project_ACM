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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define int long long
const int m1 = 998244353;
const int m2 = 1000001011;
const int K=233;
int h[2][2][410000];
int p[2][210000];
char a[210000];
char b[410000];
int n;
set<pair<int,int>> s;
inline pair<int,int> geths(int l,int r,int flag){
    int a1=(h[flag][0][r]-h[flag][0][l-1]*p[0][r-l+1]%m1+m1)%m1;
    int a2=(h[flag][1][r]-h[flag][1][l-1]*p[1][r-l+1]%m2+m2)%m2;
    return make_pair(a1,a2);
}
void work()
{
    s.clear();
    rd(n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    p[1][0]=p[0][0]=1;
    for(int i=1;i<=n;i++){
        p[0][i]=(p[0][i-1]*K)%m1;
        p[1][i]=(p[1][i-1]*K)%m2;
       // cout<<"p1[i]="<<p[0][i]<<endl;
    }
    for(int i=1;i<=n;i++)
        b[i+n]=b[i];
    h[0][0][0]=h[0][1][0]=0;
    h[1][0][0]=h[1][1][0]=0;
    for(int i=1;i<=n+1;i++){
        h[0][0][i]=(h[0][0][i-1]*K+a[i])%m1;
        h[0][1][i]=(h[0][1][i-1]*K+a[i])%m2;
       // cout<<"H"<<h[0][0][i]<<endl;
    }
    for(int i=1;i<=n*2;i++){
        h[1][0][i]=(h[1][0][i-1]*K+b[i])%m1;
        h[1][1][i]=(h[1][1][i-1]*K+b[i])%m2;
    }
    for(int i=1;i<=n;i++)
        s.insert(geths(i,i+n-1,1));
    for(int i=1;i<=n+1;i++){
        pair<int,int> t1=geths(1,i-1,0);
        pair<int,int> t2=geths(i+1,n+1,0);
        pair<int,int> ans;
        ans.first=(t1.first*p[0][n-i+1]+t2.first%m1)%m1;
        ans.second=(t1.second*p[1][n-i+1]+t2.second%m2)%m2;
        if(s.find(ans)!=s.end()){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
   //freopen("out1.txt","w",stdout);
#endif
int t = 1;
rd(t);
//cin>>t;
while (t--)
{
work();
}
return 0;
}