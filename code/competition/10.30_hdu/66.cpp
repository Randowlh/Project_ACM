#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string tmp;
int t;
int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>tmp;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            if(!((tmp[i]<='9')&&(tmp[i]>='0')))
            cout<<tmp[i];
        }
        cout<<endl;
    }
}