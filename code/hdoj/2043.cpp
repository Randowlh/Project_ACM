#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string biao="~!@#$%^";
bool check(string in){
    int flag[4];
    if(in.size()<8||in.size()>16){
        return false;
    }
    for(int i=0;i<4;i++){
        flag[i]=0;
        for(int j=0;j<in.size();j++){
            if(i==0){
                if(in[j]>='0'&&in[j]<='9'){
                    flag[i]=1;
                    break;
                }
            }else if(i==1){
                if(in[j]>='a'&&in[j]<='z'){
                    flag[i]=1;
                    break;
                }
            }else if(i==2){
                if(in[j]>='A'&&in[j]<='Z'){
                    flag[i]=1;
                    break;
                }
            }else{
                for(int k=0;k<biao.size();k++){
                    if(biao[k]==in[j]){
                        flag[i]=1;
                        break;
                    }
                }
            }
        }
    }
    if(flag[0]+flag[1]+flag[2]+flag[3]>=3){
        return true;
    }else return false;
}
int main(){
    int n;
    string tmp;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(check(tmp)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}