#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
char biao[]="abc";
int main(){
    int  t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        int flag=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!='?'&&s[i]==s[i+1]){
                cout<<-1<<endl;
                flag=1;
                break;
            }
        }
        if(flag==1){
            continue;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                for(int j=0;j<3;j++){
                    if((i-1<0||s[i-1]!=biao[j])&&(i+1>s.size()||s[i+1]!=biao[j])){
                        s[i]=biao[j];
                        break;
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}