#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define PI 3.1415927
using namespace std;
int main(){
    double r;
    while(cin>>r){
        printf("%.3lf\n",PI*r*r*r/3*4);
    }
    return 0;
}