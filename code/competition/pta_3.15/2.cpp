#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
inline int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
struct node
{
    int zi;
    int mu;
    void jia(int t)
    {
        if (t == 1)
        {
            zi = mu + zi * 2;
            mu *= 2;
            int tt = gcd(zi, mu);
            zi /= tt;
            mu /= tt;
        }
        else
        {
            mu *= 2;
            int tt = gcd(zi, mu);
            zi /= tt;
            mu /= tt;
        }
    }
};
void work()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    node x;
    x.mu = 2;
    x.zi = 1;
    double ch = 1, cl = 1;
    double ansh = 0, ansm = 0;
    for (int i = 0; i < n; i++)
    {
        ansh += ch / 2;
        ansm += cl / 2;
        if (tmp[i] == 'H')
        {
            ch /= 2;
            ch += 0.5;
            cl /= 2;
        }
        else
        {
            cl /= 2;
            cl += 0.5;
            ch /= 2;
        }
    }
    if (ansh == ansm)
    {
        cout << "HM" << endl;
    }
    else if (ansh > ansm)
    {
        cout << "H" << endl;
    }
    else
        cout << "M" << endl;
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