#include<bits/stdc++.h>
using namespace std;
#define int long long
int date[110000];
signed main(){ 
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n<=2){
        cout<<"0\n0\n";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>date[i];
    sort(date+1,date+n+1);
    int ansmi=0;
    //int ansmx=0x7FFFFFFF;
    if((date[n-1]-date[1]==n-2&&date[n]-date[n-1]>2)||(date[n]-date[2]==n-2&&date[2]-date[1]>2))
        ansmi=n-2;
    else{
    int tail=1;
    for(int i=1;i<=n;i++){
        while(tail<n&&date[tail+1]-date[i]<=n-1)
        tail++;
    //    ansmx=min(ansmx,tail-i+1);
        ansmi=max(ansmi,tail-i+1);
    }
    }
    cout<<n-ansmi<<endl;
    cout<<max(date[n]-date[2],date[n-1]-date[1])-n+2<<endl;
}