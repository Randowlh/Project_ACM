#include <bits/stdc++.h>
#define CL clear
#define PB push_back
#define hhh cerr << "hhh" << endl
#define see(x) cerr << (#x) << '=' << x << endl
#define int long long
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
std::mt19937 rng(time(0));
const int N = 2e5+10;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
inline int rd() {
  int p=0; int f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}

int ss; pii a[N]; int len =0; int b[N],c[N]; int n,r;
int getans(int *d) {
  int s = 0;
  for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) s+=(a[d[i]].fi - a[d[j]].fi) * (a[d[i]].fi - a[d[j]].fi) + (a[d[i]].se - a[d[j]].se) * (a[d[i]].se - a[d[j]].se);

  // for(int i=1;i<=n;i++) printf("%lld %lld\n",a[d[i]].fi,a[d[i]].se); printf(":\n");
  // printf("%lld\n",s);
  return s;
}

void solve() {
  // for(int i=1;i<=2*n;i++) {
  //   printf("%.6lf %.6lf\n",hr[i],sr[i]);
  // }

  int ans ;
  for(int i=1;i<=n;i++) b[i] = rng() % len + 1;
  ans = getans(b);
  ss = max(ss , ans);
  // printf("%.8lf\n",getans(140));
  // for(int i=1;i<=len;i++) printf("%lld %lld\n",a[i].fi,a[i].se);
  // printf("%lld\n",ans);
  int t = len;
  while(t >= 1) {
    bool flag = 1;
    while(flag) {
      flag = 0;
      for(int i=1;i<=8;i++) c[i] = b[i];
      for(int i=1;i<=8;i++) {
        c[i] = (b[i] + t) % len + 1;
        int tp = getans(c);
        if(ans < tp){ans = tp; ss = max(ss , ans); for(int i=1;i<=n;i++) b[i] = c[i]; flag = 1;}
        else {
          if(exp((tp - ans) )/ t > (rng()%10000)/10000.0) {
            for(int i=1;i<=n;i++) b[i] = c[i]; ans =  tp;
          }
        }
        c[i] = (b[i] - t + len) % len + 1;
        tp = getans(c);
        if(ans < tp){ans = tp; ss = max(ss , ans); for(int i=1;i<=n;i++) b[i] = c[i]; flag = 1;}
        else {
          if(exp((tp - ans) )/ t > (rng()%10000)/10000.0) {
            for(int i=1;i<=n;i++) b[i] = c[i]; ans =  tp;
          }
        }
      }
    }
    t = min((int)(t*0.9),t-1);
  }
  // printf("%lld\n",ss);
}



signed main() {
  // freopen("a.in","r",stdin);
  int t = rd();
  for(int T=1;T<=t;T++) {
    // n = rd();
    n = rd(); r=rd();
   
      len = 0;
      for(int i=-r;i<=r;i++) {
        a[++len] = MP(i,(int)sqrt(r*r-i*i));
        a[++len] = MP(i,-(int)sqrt(r*r-i*i));
      }
      // printf("%lld\n",len);
      ss = 0;
     for(int j=1;j<=100000;j++) solve();
      printf("%lld\n",ss);
  }
  return 0;
}
