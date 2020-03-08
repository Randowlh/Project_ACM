#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    vector<int> ans;
    int tol = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            cout << 1 << endl;
            cout << i + 1 << endl;
            return;
        }
        else
        {
            if (i != 0)
            {
                cout << 2 << endl;
                cout << i << ' ' << i + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}