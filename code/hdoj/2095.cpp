#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int tmp=0;
    while(cin>>n){
        if(n==0)
        break;
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            ans^=tmp;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}