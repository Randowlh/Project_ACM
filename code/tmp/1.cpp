#include <bits/stdc++.h>
using namespace std;
#define int long long
class test
{
public:
    int a;
    virtual void aa() {}
    virtual void bb() = 0;
};
signed main()
{
    test aa;
    cout << aa.tol() << endl;
    test bb;
    cout << aa.tol() << endl;
}