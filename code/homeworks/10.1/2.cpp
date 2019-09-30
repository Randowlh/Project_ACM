#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double x1,x2,y12,y22;
int main(){
    cin>>x1>>y12>>x2>>y22;
    printf("%.2f",sqrt( ((x1-x2)*(x1-x2))+((y12-y22)*(y12-y22))));
    return 0;
}