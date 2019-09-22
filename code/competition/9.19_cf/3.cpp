#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c;
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        int ans=0;
        cin>>a>>b>>c;
        if(a!=0&&b!=0&&c!=0){
            tmp=min(a,min(b,c));
            a-=tmp;
            b-=tmp;
            c-=tmp;
            ans+=tmp;
        } 
        if(a!=0&&b!=0&&a+b>=3){
            ans+=min(a,min(b,(a+b)/3));
        }
        printf("%d\n",ans);
    }
    return 0;
}
