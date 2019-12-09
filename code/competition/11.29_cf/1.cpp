#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int r,g,b;
        int ans=0;
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[1]+a[0]<=a[2]){
            cout<<a[1]+a[0]<<endl;
            continue;
        }else{
            a[0]-=a[2]-a[1];
            ans+=a[2]-a[1];
            ans+=a[0]/2*2;
            a[2]-=a[0]/2;
            a[1]-=a[0]/2;
            ans+=a[1];
        }
        cout<<ans<<endl;
    }
    return 0;
}