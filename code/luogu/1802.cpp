#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1010];
int v[1010];
int w[1010];
signed main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    int ans = 0;
    for (int i = 0; i < n;i++){
        cin >> a >> b >> w[i];
        ans += a;
        b -= a;
        v[i] = b;
    }
    for (int i = 0; i < n;i++)
        for (int j =m; j >= w[i];j--)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout << 5*(dp[m] + ans) << endl;
}