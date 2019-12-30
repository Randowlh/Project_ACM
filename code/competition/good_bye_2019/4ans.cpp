#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n,k;
    cin>>n>>k;
    int big=0,sm=0;
    int base=0;
    int basect=0;
    cout<<"? ";
    for(int i=1;i<=k;i++){
        cout<<i<<' ';
    }
    cout<<endl;
    int pos,num;
    cin>>pos>>num;
    base=num;
    basect++;
    int flag=0;
    for(int i=1;i<=k;i++){
        cout<<"? ";
        for(int j=1;j<=k+1;j++){
            if(i!=j)
            cout<<j<<' ';
        }cout<<endl;
        cin>>pos>>num;
        if(flag==0){
            //flag=1;
            if(num>base){
                sm+=basect;
                flag=1;
            }
            if(num<base){
                big+=basect;
                flag=2;
            }
            if(num==base){
                basect++;
            }
        }else
        if(flag==1){
            if(num==base){
                sm++;
            }else
            {
                big++;
            }
        }else
        if(flag==2){
            if(num==base){
                big++;
            }else{
                sm++;
            }
        }
    }
    cout<<"! "<<big<<endl;
    return ;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}