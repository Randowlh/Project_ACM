#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const double tol = 3600 * 12;
double abss(double a){
    if(a<0){
        return -a;
    }else return a;
}
int main()
{   
    while(true){
    double d;
    cin >> d;
    if (d == -1)
    {
        return 0;
    }
    int happy = 0;
    double h, m, s;
    for (int i = 0; i < 3600 * 12; i++)
    {
        h = (double)(i * 360) / tol;
        m = (double)(i % 3600) / 10.0;
        s = (double)(i % 60) * 6.0;
        if(d<abss(h-s)&&abss(h-s)<360-d&&d<abss(m-s)&&abss(m-s)<360-d&&d<abss(h-m)&&abss(h-m)<360-d){
            happy++;
        }
    }
    printf("%.3f",(double)happy/tol*100);
    }
}