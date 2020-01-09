#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    while(getline(cin,tmp)){
        double ans=0;
        double m=0;
        int flag=0;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]==' '){
                continue;
            }else if(tmp[i]=='A'){
                ans+=4;
                m++;
            }else if(tmp[i]=='B'){
                ans+=3;
                m++;
            }else if(tmp[i]=='C'){
                ans+=2;
                m++;
            }else if(tmp[i]=='D'){
                ans++;
                m++;
            }else if(tmp[i]=='F'){
                m++;
            }else {
                flag=1;
                cout<<"Unknown letter grade in input"<<endl;
                break;
            }
        }
        if(flag==0){
            printf("%.2f\n",ans/m);
        }
        //return ;
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}