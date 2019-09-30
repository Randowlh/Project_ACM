#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int ans1,ans2,ans3;
    double tmp;
    int n;
    while(true){
        ans1=0;
        ans2=0;
        ans3=0;
        cin>>n;
        if(n==0){
            return 0;
        }else{
            for(int i=0;i<n;i++){
                scanf("%lf",&tmp);
                if(tmp<0){
                    ans1++;
                }else if(tmp>0){
                    ans3++;
                }else{
                    ans2++;
                }
            }
            printf("%d %d %d\n",ans1,ans2,ans3);
        }

    }
    return 0;
}