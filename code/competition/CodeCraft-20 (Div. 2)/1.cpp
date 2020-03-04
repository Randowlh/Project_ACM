#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, m;
    cin >> n >> m;
    int tmp;
    vector<int> v;
    ll tol = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        tol += tmp;
        v.push_back(tmp);
    }
    if (tol > m)
    {
        cout << m << endl;
    }
    else
        cout << tol << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}