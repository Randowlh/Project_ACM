#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int st[500100];
int tail;
int main(){
    int t;
    cin>>t;
    int n;
    for(int q=0;q<t;q++){
        cin>>n;
        int tmp;
        tail=0;
        int now=-1;
        cin>>tmp;
        now=tmp;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            scanf("%d",&tmp);
            if(tmp!=now){
                now=tmp;
                st[tail]=cnt;
                tail++;
                cnt=0;
            }
            cnt++;
        }
        if(cnt!=0){
            now=tmp;
                st[tail]=cnt;
                tail++;
                cnt=0;
        }
        int flag1=0;
        if(n%2!=0){
            flag1=1;
        }
      now=0;
        for(int i=tail-1;i>=0;i--){
            now+=st[i];
            tail--;
            if(now>=n/2+flag1){
                break;
            }
        }
        if(tail<2){
            cout<<"0 0 0"<<endl;
            continue;
        }
        now=n-now;
       // cout<<now<<"dasd"<<endl;
        int g=st[0];
        int flag=0;
        int b=0;
        for(int i=tail-1;i>0;i--){
            b+=st[i];
            if(b>g&&now-b-g>g){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<g<<' '<<now-b-g<<' '<<b<<endl;
        }else{
            cout<<"0 0 0"<<endl;
        }
        
    }
    return 0;
}