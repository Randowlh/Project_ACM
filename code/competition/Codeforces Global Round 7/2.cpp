#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    ll now = 0;
    ll tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp >= 0)
        {
            now += tmp;
            cout << now << ' ';
        }
        else
            cout << now + tmp << ' ';
    }
    cout << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}