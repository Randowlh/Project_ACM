#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
int  a,b,c;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
    int ans=inf;
    cin>>a>>b>>c;
    for(int i=a-1;i<a+2;i++)
        for(int j=b-1;j<b+2;j++)
            for(int k=c-1;k<c+2;k++){
            ans=min(ans,abs(i-k)+abs(i-j)+abs(j-k));    
            }
            cout<<ans<<endl;
    }
    return 0;
}