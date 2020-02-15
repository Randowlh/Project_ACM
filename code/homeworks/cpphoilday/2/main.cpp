#include "date.cpp"
#include <iostream>
using namespace std;
ostream &operator<<(ostream &ot, mx c)
{
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            ot << setw(5) << *(c.a + i * c.size() + j);
        }
        ot << endl;
    }
    return ot;
}
int main()
{
    int n;
    cin >> n;
    mx t;
    t.make(n);
    cout << t;
    t.clear();
    return 0;
}