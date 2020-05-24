#include <bits/stdc++.h>
using namespace std;
class node
{
    int a;

public:
    node(int x) : a(x) {}
    void out()
    {
        cout << a << endl;
    }
};
int main()
{
    auto sp1 = make_shared<int>(543321);

    shared_ptr<int> sp2;

    sp2 = sp1;
    cout << sp1.unique() << endl;
}