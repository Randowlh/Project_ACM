/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7;
int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int x; string s; cin >> x >> s;
        int currLen = (int)s.size();
        for (int i = 0; i < x; i++) {
            int curr = s[i] - '0';
            // length need to grow
            if (currLen < x) {
                for (int j = 1; j < curr; j++)
                    if ((int)s.size() < x) {
                        for (int l = i + 1; l < currLen; l++)
                            if ((int)s.size() < x) s += s[l];
                    }
            }
            // calculate current length of string
            int d = (currLen - i - 1 + mod) % mod;
            currLen = ((i + 1) + (ll)d * curr) % mod;
        }
        cout << currLen << '\n';
    }
    return 0;
}