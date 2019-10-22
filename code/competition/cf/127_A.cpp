#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int bali(int a,int b,int c){
    int ans=0;
    if(a+c-(a+b+c)/2>=c){
        ans=c;
    }else{
        ans=a+c-(a+b+c)/2;
    }
    return ans;
}
int main(){
    int n;
    int a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        int  ans= bali(a,b,c);
        printf("%d\n",ans);
    }
    return 0;
}
