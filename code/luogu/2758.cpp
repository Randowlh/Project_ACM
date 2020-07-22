#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int main(){
    string a, b;
    string tmp;
    a.push_back(' ');
    b.push_back('.');
    cin >> tmp, a += tmp;
    cin >> tmp, b += tmp;
    for (int i = 0;i<2000; i++)
        dp[0][i] = dp[i][0] = i;
        for (int i = 1; i < a.size(); i++)
            for (int j = 1; j < b.size(); j++)
            {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else{
                dp[i][j] = 0x7FFFFFFF;
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                dp[i][j] = min(dp[i][j - 1]+1, dp[i][j]);
                dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    cout << dp[a.size()-1][b.size()-1] << endl;
}