#include<cstdio>
#include<iostream>
using namespace std;
int ar[10000];
int n;
int main(){
    while(true){
        int min=999999;
        int mint=-1;
        scanf("%d",&n);
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            if(ar[i]<min){
                min=ar[i];
                mint=i;
            }
        }
        int t=ar[mint];
        ar[mint]=ar[0];
        ar[0]=t;
        for(int i=0;i<n-1;i++){
            printf("%d ",ar[i]);
        }
        printf("%d\n",ar[n-1]);
    }
    return 0;
}