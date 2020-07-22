#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, l;
int h[2010], w[2010];
int prw[2010];
int dp[2010];
struct st_table
{
    int date[2010];
    int mx[2010][12];
    inline void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
signed main(){
    //freopen("in.txt", "r", stdin);
    cin >> n >> l;
    for (int i = 1; i <= n;i++)
        cin >> h[i] >> w[i],b.date[i]=h[i];
    b.RMQ(n);
    dp[0] = 0;
    for (int i = 1; i <= n;i++)
        prw[i]=prw[i-1]+w[i];
    for (int i = 1; i <= n;i++){
        dp[i] = dp[i - 1] + h[i];
        for (int j = 0; j <= i-1;j++){
            if(prw[i]-prw[j]<=l){
                dp[i] = min(dp[i], dp[j]+ b.query(j+1 , i));
            //    cout << "i=" << i << ' ' << j << endl;
            }
        }
    }
    cout<<dp[n]<<endl;
}   