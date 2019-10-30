#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string tmp;
int tail=0;
string st[1010];
/*
void pr(int k){
 if(st[k].empty()){
       return;
    }
    for(int i=0;i<st[k].size();i++){
        if(st[k][i]<='z'&&st[k][i]>='a'){
            st[k][i]-='a'-'A';
        }else{
            st[k][i]+='a'-'A';
        }
    }
    cout<<st[k];
    return;
}*/
/*
void updown(){
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]<='z'&&tmp[i]>='a'){
            tmp[i]-='a'-'A';
        }else{
            if(tmp[i]<='Z'&&tmp[i]>='A'){
                tmp[i]+='a'-'A';
            }
        }
    }
    return;
}*/
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>tmp;
        tail=0;
       // updown();
        for(int i=0;i<1010;i++){
            st[i].clear();
        }
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]>='0'&&tmp[i]<='9'){
                tail++;
            }else{
                st[tail].push_back(tmp[i]);
            }
        }
        if(!(tmp[tmp.size()-1]>='0'&&tmp[tmp.size()-1]<='9')){
            tail++;
        }
        sort(st,st+tail+1);
        for(int i=0;i<=tail;i++){
            if(!st[i].empty())
            cout<<st[i];
        }
        cout<<endl;
    }
    return 0;
}