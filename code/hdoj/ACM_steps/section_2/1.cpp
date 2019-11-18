#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define pi 3.1415927
int main(){
    double t,d,r;
    int cnt=1;
    while(cin>>d>>r>>t){
        if(r==0){
            break;
        }
        printf("Trip #%d: ",cnt);
        cnt++;
        printf("%.2f ",d*r*pi/(5280*12));
        printf("%.2f\n",d*r*pi*3600/(t*5280*12));
    
    }
    return 0;
}