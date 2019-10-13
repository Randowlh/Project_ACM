#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
int v[10010],w[10010],dp[10010],s[10010],f[10010];
int main(){
    int th1,th2,tm1,tm2;
    scanf("%d:%d",&th1,&tm1);
    scanf("%d:%d",&th2,&tm2);
    scanf("%d",&n);
    m=th2*60-th1*60-tm1+tm2;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&w[i],&v[i],&s[i]);
    }
    for(int i=0;i<n;i++){
        if(s[i]==0){
            for(int j=0;j<=m;j++){
                if(j>=w[i]){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                }
            }
        }else{  
                if(s[i]==1){
                for(int j=m;j>=0;j--){
                    if(j>=w[i]){
                    dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                    }
                }
            }else{
                int tmp=1;
                while(tmp<=s[i]){
                for(int j=m;j>=0;j--){
                    if(j>=w[i]*tmp){
                    dp[j]=max(dp[j],dp[j-w[i]*tmp]+v[i]*tmp);
                    }
                }
                s[i]-=tmp;
                tmp*=2;
                }
                if(s[i]!=0){
                for(int j=m;j>=0;j--){
                    if(j>=w[i]*s[i]){
                        dp[j]=max(dp[j],dp[j-w[i]*s[i]]+v[i]*s[i]);
                    }
                }
                }
            }
            }
        }

    printf("%d\n",dp[m]);
    return 0;
}