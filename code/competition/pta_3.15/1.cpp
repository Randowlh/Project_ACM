#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    ll n;
    cin >> n;
    int tmp;
    vector<int> v;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < 0)
            cnt++;
        v.push_back(tmp);
    }
    cout << cnt * (n - 1) << endl;
}
int main()
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