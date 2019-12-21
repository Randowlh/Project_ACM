#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
const int inf =0x7FFFFFFF;
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){

    string t;
    cin>>t;
    int flag=0;
    for(int i=0;i<t.size();i++){
        if(t[i]=='0'){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"cyan"<<endl;
        continue;
    }
    int cnt=0;
    flag=0;
    for(int i=0;i<t.size();i++){
        cnt+=t[i]-'0';
        if((t[i]-'0')%2==0){
            flag++;
        }
    }
    if(flag>=2&&cnt%3==0)
    cout<<"red"<<endl;
    else 
    cout<<"cyan"<<endl;
    }
}