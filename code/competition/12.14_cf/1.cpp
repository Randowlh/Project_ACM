#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf = 0x7FFFFFFF;
int a[200010];
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        int ans=0;
        int now=1;
        while(now<=n){
            int flag=0;
            for(int i=1;i<=9;i++){
                if(now*i<=n){
                    ans++;
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
            now=now*10+1;
        }
        cout<<ans<<endl;
    }
    return 0;

}