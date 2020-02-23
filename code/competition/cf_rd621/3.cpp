#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
ll dp[26][26];
ll letter[26];
void work()
{
    ll ans = 0;
    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[j][tmp[i] - 'a'] += letter[j];
            ans = max(dp[j][tmp[i] - 'a'], ans);
        }
        letter[tmp[i] - 'a']++;
        ans = max(letter[tmp[i] - 'a'], ans);
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        work();
    }
    return 0;
}