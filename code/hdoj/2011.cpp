#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
double f[1010];
int main(){ 
    memset(f,-1,sizeof(f));
     int n;
     f[1]=1;
     cin>>n;
     int tmp;
     for(int i=2;i<=1000;i++){
         if(i%2==0){
             f[i]=f[i-1]-1/(double)i;
         }else f[i]=f[i-1]+1/(double)i;     }
     for(int i=0;i<n;i++){
         cin>>tmp;
         printf("%.2f\n",f[tmp]);
     }
     return 0;
}