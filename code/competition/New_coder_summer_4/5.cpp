#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int d[100000];
int h[100000];
int tail;
int n;
int t;
void up(int x) {
  while (x > 1 && h[x] > h[x / 2]) {
    swap(h[x], h[x / 2]);
    d[x] = t;
    d[t] = x;
    x /= 2;
  }
}
void down(int x) {
  while (x * 2 <= n) {
    t = x * 2;
    if (t + 1 <= n && h[t + 1] > h[t]) t++;
    if (h[t] <= h[x]) break;
    swap(h[x], h[t]);
   
    x = t;
  }
}
void erase(int x){
    if(x>=tail)
        return;
    if(h[x*2]<h[x*2+1]){
        h[x] = h[x * 2];
        d[x * 2]=d[x];
        erase(x * 2);
    }
    else
    {
        h[x] = h[x * 2 + 1];
        d[x * 2] = d[x];
        erase(x * 2 + 1);
    }
}
void build_heap_1() {
    int n = 100;
    for (int i = 1; i <= n; i++)
        up(i);
}
void work()
{
    build_heap_1();
    for (int i = 10; i >= 1;i--){
        d[i] = i;
        h[i] = i;
        cout << h[i] << endl;
        up(i);
        tail++;
    }
    // for (int i = 0; i < 100;i++){
    //     cout << d[i] << endl;
    // }
    erase(d[9]);
    for (int i = 0; i < 10;i++){
        cout << h[i] << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}