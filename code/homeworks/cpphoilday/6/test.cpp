#include <bits/stdc++.h>
using namespace std;
class test
{
private:
    int k;

public:
    test(int a, int b = 3)
    {
        k = a * b;
    }
    ~test()
    {
        cout << "ohhhh no" << endl;
        return;
    }
    test(string a)
    {
        k = a[0];
    }
    int show() { return k; }
};
int main()
{
    test a(2, 4234);
    int aa{1};
    cout << aa << endl;
    cout
        << a.show() << endl;
}