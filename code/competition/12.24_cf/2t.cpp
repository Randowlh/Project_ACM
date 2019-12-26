#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll date[2000100];
int main(){
   // freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    //cout<<0x7FFFFFFF<<endl;
    for(int q=0;q<t;q++){
        ll n,k,p;
        cin>>n>>p>>k;
        for(int i=0;i<n;i++){
            scanf("%d",&date[i]);
        }
        ll tmp=p;
        ll tol=0;
        ll tolt=0;
        sort(date,date+n);
        if(tmp<date[0]){
            cout<<0<<endl;
            continue;
        }
        tmp-=date[0];
        tolt++;
        for(int i=2;i<n;i+=2){
            //cout<<i<<'l'<<endl;
            tmp-=date[i];
            if(tmp<0)
            break;
            else 
            tolt+=2;
        }
        tol=tolt;
        tmp=p;
        tolt=0;
        for(int i=1;i<n;i+=2){
            //cout<<i<<'d'<<endl;
            tmp-=date[i];
            if(tmp<0){
                break;
            }
            else 
            tolt+=2;
        }
        cout<<max(tol,tolt)<<endl;
    }
    return 0;
}