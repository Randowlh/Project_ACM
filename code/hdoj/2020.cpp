#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int abss(int x){
    if(x<0)return -x;
    else return x;
}
bool cmp(int a,int b){
    return abss(a)>abss(b);
}
int date[10000];
int main(){
    int n;
    while(true){
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%d",&date[i]);
        }
        sort(date,date+n,cmp);
        for(int i=0;i<n-1;i++){
            printf("%d ",date[i]);
        }
        printf("%d\n",date[n-1]);
    }
    return 0;
}