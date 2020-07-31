#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) { return b ? gcd(b, a % b): a;}
#define int long long
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
struct st_table
{
    int date[200100];
    int mx[200100][30];
    inline void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = gcd(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return gcd(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
signed main(){
    ios::sync_with_stdio(false);
    int n,m;
    rd(n),rd(m);
    for(int i=1;i<=n;i++){
        rd(b.date[i]);
    }
    b.RMQ(n);  
    int u,v;
    for(int i=0;i<m;i++){
        rd(u),rd(v);
        printf("%lld\n",b.query(u,v));
    }
}