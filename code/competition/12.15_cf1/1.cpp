#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
string a;
string biao[4]={"po","desu","masu","mnida"};
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        cin>>a;
        int flag=-1;
        for(int i=0;i<4;i++){
            if(a.size()<biao[i].size())
            continue;
            else{
                int tf=0;
                for(int j=0;j<biao[i].size();j++){
                    if(biao[i][biao[i].size()-j]!=a[a.size()-j]){
                        tf=1;
                        break;
                    }
                }
                if(tf==0){
                    flag=i;
                    break;
                }
            }
        }
        if(flag==0){
            cout<<"FILIPINO"<<endl;
        }else if(flag==1||flag==2){
            cout<<"JAPANESE"<<endl;
        }else cout<<"KOREAN"<<endl;
    }
    return 0;
}