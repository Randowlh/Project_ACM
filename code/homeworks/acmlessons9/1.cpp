#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double f(double xx){return 42*pow(xx,6)+48*pow(xx,5)+21*pow(xx,2)+10*xx;}
int main(){
        int  t;
        cin>>t;
        double ans;
        double n;
        double s=0;
        double e=100;
        for(int i=0;i<t;i++){
            cin>>n;
            double s=0;
        double e=100;
            while(e-s>0.00000001){
                double mid=(s+e)/2;
                if(f(mid)<=n){
                    s=mid;
                }else{
                    e=mid;
                }
            }
            printf("%.4lf\n",(6*pow(e,7)+8*pow(e,6)+7*pow(e,3)+5*e*e-n*e));
           // printf("%.4f\n",f(1.6152));
        }
        return 0;
}