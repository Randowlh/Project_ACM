#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int date[300010];
int main(){
    int  n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
       // ans+=date[i]/2;
     //   date[i]%=2;
    }
    ll ans1,ans2;
    ans1=0;
    ans2=0;
    int h=0;
    for(int i=0;i<n;i++){
        if(h==0){
            h++;
            ans1+=date[i]-date[i]/2;
            ans2+=date[i]/2;
        }else{
            h--;
            ans2+=date[i]-date[i]/2;
            ans1+=date[i]/2;
        } 
    }
    ans=min(ans1,ans2);
    cout<<ans<<endl;
    return 0;
}