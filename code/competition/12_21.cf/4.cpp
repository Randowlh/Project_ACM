#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
int date[300010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    int tmp=date[0];
    int cnt=1;
    ll ans=0;
    for(int i=1;i<n;i++){
        if(date[i]==tmp){
            cnt++;
        }else{
            if(date[i]>tmp&&(date[i]-tmp)%2==0){
                ans-=(date[i]-tmp)/2*cnt;
                tmp=date[i];
                cnt++;
            }else if(date[i]<tmp&&(date[i]-tmp)%2==0){
                ans+=(date[i]-tmp)/2*cnt;
                tmp=date[i];
                cnt++;
            }else{
            //ll tmp=0;
            ans+=tmp/2*cnt;
            ans+=(tmp%2)*cnt/2;
            cnt=1;
            }
        }
    }
    ans+=tmp/2*cnt;
    ans+=cnt/2;
    cout<<ans<<endl;
    return 0;
}