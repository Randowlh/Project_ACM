
#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define PI 3.1415927
using namespace std;
int main(){
    double r;
    while(cin>>r){
        if(r>100)cout<<"Score is error!\n";
        else if(r>=90)cout<<"A\n";
        else if(r>=80)cout<<"B\n";
        else if(r>=70)cout<<"C\n";
        else if(r>=60)cout<<"D\n";
        else if(r>=0)cout<<"E\n";
        else cout<<"Score is error!\n";
    }
    return 0;
}