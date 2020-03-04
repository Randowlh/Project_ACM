#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    int mix = 1;
    string ans = tmp;
    for (int i = 1; i < n; i++)
    {
        string now;
        now.clear();
        //   cout << tmp.substr(i, 9999999) << endl;
        now = now + tmp.substr(i, 999999);
        string t = tmp.substr(0, i);
        if ((n - i) % 2 == 1)
            reverse(t.begin(), t.end());
        now = now + t;
        if (now < ans)
        {
            ans = now;
            mix = i + 1;
        }
    }
    cout << ans << endl;
    cout << mix << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}
/* 

abab
1
ertyqw
3
aaaaa
1
aksala
6
avjsmbpfl
5
p
1


 */
