#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    int fl = 0;
    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < n; i++)
    {
        cnta += a[i];
        cntb += b[i];
        if (a[i] == 1 && b[i] == 0)
        {
            fl++;
        }
    }
    if (cnta > cntb)
    {
        cout << 1 << endl;
        return;
    }
    else if (fl == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        if ((cntb - cnta + 1) % fl == 0)
        {
            cout << 1 + (cntb - cnta + 1) / fl << endl;
        }
        else
        {
            cout << 2 + ((cntb - cnta + 1) / fl) << endl;
        }
    }
    return;
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