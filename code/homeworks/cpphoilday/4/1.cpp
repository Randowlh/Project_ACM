#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307
class Circle
{
private:
    double r;
    double area()
    {
        return r * r * PI;
    }
    double round()
    {
        return r * PI * 2.0;
    }

public:
    double cost(double a)
    {
        r = a;
        return 20.0 * area() + 35.0 * round();
    }
} tmp;
int main()
{
    double n;
    cin >> n;
    printf("%.2f\n", tmp.cost(n));
    return 0;
}