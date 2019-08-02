#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    long long a,b,c;
    for(int i=1;i<=n;i++){
    cin>>a>>b>>c;
    if(a+b>c){
        printf("Case #%d: true\n",i);
    }else{
        printf("Case #%d: false\n",i);
    }
    }
    return 0;
}
