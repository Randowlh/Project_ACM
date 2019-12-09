#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{   
    double x;
    double y;
    /* data */
} date[100010];
double chac(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)
        break;
        for(int i=0;i<n;i++){
                cin>>date[i].x>>date[i].y;           
        }
        double ans=0;
        for(int i=0;i<n;i++){
            ans+=chac(date[i].x,date[i].y,date[(i+1)%n].x,date[(i+1)%n].y)/2;
        }
        printf("%.1f\n",fabs(ans));
    }
    return 0;
}