#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int date[1100000];
int tail=0;
int main(){
    int t=0;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        tail=0;
        date[tail]=0;
        tail++;
        date[tail]=1;
        tail++;
        //cout<<"yes"<<endl;
        for(int i=2;i<=100000&&i<=n;i++){
            if(n/i>n%i){
                date[tail]=i;
                tail++;
            }
        }
        //cout<<"yes"<<endl;
        int t=n/date[tail-1];
        if(t>1)
        for(int i=t;i>=1;i--){
            date[tail]=n/t;
            tail++;
        }
        cout<<tail<<endl;
        for(int i=0;i<tail;i++){
            printf("%d ",date[i]);
        }
        cout<<endl;
    }
    return 0;
}