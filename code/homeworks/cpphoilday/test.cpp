#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
class a
{
    T date1;
    U date2;

public:
    a(T date11, U date22) : date1(date11), date2(date22) {}
    void out()
    {
        cout << "U=" << U << ' ' << "T=" << T << endl;
        cout << U + T << endl;
    }
};

int main()
{
    a<int, int> k(1, 2LL);
    k.out();
}