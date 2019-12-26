#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int date[200010];
int ks[200010];
int dp[200020];
int main()
{
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        //k++;
        for(int i=0;i<n;i++){
            scanf("%d",&date[i]);
        }
        sort(date,date+n);
      //  int now=k;
        for(int i=0;i<=n;i++){
            dp[i]=0;
            ks[i]=0;
        }
        ll tol=0;
        int cnt=1;
        int flag=0;
        int now=k-1;
        while(true){
            if(now>n)
            break;
            
            for(int i=now;i<now+k;i++){
                if(ks[i%k]+date[i]>p){
                    flag=1;
                    break;
                }
            }
            
           //cout<<"yes"<<endl;
            if(flag==1)
            break;
            else
            for(int i=now;i<now+k;i++){
                cout<<ks[i%k]<<endl;
                ks[i%k]+=date[i];
                if(ks[i%k]>p){
                    flag=1;
                    break;
                }
            }
            cnt++;
            now+=k;
        }
        for(int i=0;i<k;i++){
           cout<<ks[i]<<endl;
        }
        dp[0]=0;
        for(int i=1;i<=k;i++){
            dp[i]+=dp[i-1]+date[i-1];
        }
        if(flag==0){
            
        }else
        for(int i=k-1;i>=0;i--){
            if(dp[k-i]+ks[i+1]<=p){
                cout<<(cnt-1)*k+k-i<<endl;
                break;
            }
        }
        
        //cout<<tol<<endl;
        
    }
    return 0;
}