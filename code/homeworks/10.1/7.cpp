#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double lm;
    cin>>lm;
    printf("%d %d\n",(int)((lm/100/0.3048)*12)/12,(int)((lm/100/0.3048)*12)%12);
    return 0;
}