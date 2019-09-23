#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double abss(double x){
    if(x<0)return -x;
    else
    {
        return x;
    }
    
}
int main(){
    double ans;
    while(cin>>ans){
        printf("%.2lf\n",abss(ans));
    }
    return 0;
}