#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
unsigned long long a,b,tmp;
int main(){
    int  n;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>a>>b;
    tmp=a-b;
    if(tmp==2||tmp==1){
        printf("NO\n");
    }else
    if(tmp==3){
        printf("NO\n");
    }else
    if((tmp+1)%6==0||(tmp-1)%6==0){
    printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    
}
}
