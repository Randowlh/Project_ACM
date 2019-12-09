#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int date[1100000];
int tail=0;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        int now=1;
        int step=1;
        tail=0;
        date[tail]=0;
        tail++;
        date[tail]=1;
        tail++;
        while(now<n){
            now+=step;
            if(n/now>n%now){
                date[tail]=now;
                tail++;
                step=now-date[tail-1];
                now+=step;
                continue;
            }
            
        }
        printf("%d\n",tail);
        for(int i=0;i<tail;i++){
            printf("%d ",date[i]);
        }
        cout<<endl;
    }
    return 0;
}