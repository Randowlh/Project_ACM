#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    string a;
    char e;
    int t;
    /* data */
};
int dis(string a, string b)
{
    int h1 = (a[0] - '0') * 10 + a[1];
    int m1 = (a[3] - '0') * 10 + a[4];
    int h2 = (b[0] - '0') * 10 + b[1];
    int m2 = (b[3] - '0') * 10 + b[4];
    return h2 * 60 + m2 - m1 - h1 * 60;
}
void work()
{
    map<int, node> M;
    double tol = 0;
    int cnt = 0;
    string a;
    char e;
    int t;
    while (cin >> t >> e >> a)
    {
        if (t == 0)
        {
            break;
        }
        node x;
        x.a = a;
        x.e = e;
        x.t = t;
        if (e == 'S')
        {
            M[t] = x;
        }
        else
        {
            if (M.count(t) != 0)
            {
                cnt++;
                tol += dis(M[t].a, a);
                M.erase(t);
            }
        }
    }
    if (cnt == 0)
        cout << 0 << ' ' << 0 << endl;
    else
        printf("%d %.0f\n", cnt, tol / cnt);
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}