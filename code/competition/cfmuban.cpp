#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
class ab
{
public:
    virtual void output() { cout << "NMSL" << endl; }
};
class key : public ab
{
public:
    void output() { cout << "Hello" << endl; }
};
class key2 : public ab
{
public:
    void output() { cout << "WTF" << endl; }
};
void work()
{
    vector<ab *> v;
    ab *aa = new ab;
    key *a = new key;
    key2 *b = new key2;
    v.push_back(aa);
    v.push_back(a);
    v.push_back(b);
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->output();
    }
    return;
}
signed main()
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