#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,r;
int t;
double pi=acos(-1.0);
double a[10100];
bool check ( double x )
{
    int count = 0;
    for ( int i = 0; i < n;  i++ )
    {
        count += int ( a[i] / x );
    }
    if ( count >= r + 1 )
    {
         return true;
    }
    else
    {
         return false;
    }
}
int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>r;
        double tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            a[i]=tmp*tmp*pi;
        }
        double l=0;
        double e=10000;
        double mid;
        while(e-l>0.00000001){
            mid=(l+e)/2;
            if(check(mid)){
                l=mid;
            }else{
                e=mid;
            }
        }
        printf("%.4lf\n",mid);
    }
    return 0;
}