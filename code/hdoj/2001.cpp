#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double abss(double x){
    if(x<0){
        return -x;
    }else{
        return x;
    }
}
int main(){
    double ans;
    double x1,x2,y1,y2;
   while( scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!= EOF){
    double tmpx;
    double tmpy;
    tmpx=abss(x1-x2);
    tmpy=abss(y1-y2);
    tmpx=tmpx*tmpx;
    tmpy=tmpy*tmpy;
    ans=sqrt(tmpx+tmpy);
    printf("%.2f\n",ans);
   }
    return 0;
}