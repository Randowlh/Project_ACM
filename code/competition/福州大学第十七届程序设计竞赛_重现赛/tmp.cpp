#include<stdio.h> 
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdio>
#include<string>
#include<deque>
#include<iostream>
using namespace std;
typedef long long ll;
ll dp[22][22][22][4];
void solve() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        memset(dp, 0, sizeof(dp));
        dp[n][m][k][3] = 1;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                for (int p = k; p >= 0; p--) {
                    for (int l = 0; l <= 3; l++) {
                        if (l == 3) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 0) {
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 1) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (p > 0) dp[i][j][p-1][2] += dp[i][j][p][l];
                        }
                        if (l == 2) {
                            if (i > 0) dp[i-1][j][p][0] += dp[i][j][p][l];
                            if (j > 0) dp[i][j-1][p][1] += dp[i][j][p][l];
                        }
                    }
                }
            }
        }
        ll sum = 0;
        for (int l = 0; l <= 3; l++) {
            sum += dp[0][0][0][l];
        }
        cout << sum << endl;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    solve();
}