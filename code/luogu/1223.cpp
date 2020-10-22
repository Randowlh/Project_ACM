#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int q=1;q<=t;q++){
        int n;
        scanf("%d", &n);
        int ans=0;
        int t=n%10;
        ans+=(t-1)*10;
        int cnt=1;
        while(n){
            ans+=cnt;
            cnt++;
            n/=10;
        }
        printf("%d\n",ans);
    }
}