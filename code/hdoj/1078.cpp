#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
struct trie
{
    int nex[10000][26];
    bool ex[10000];
    int num[10000];
    int cnt;
    bool et(string a){
        int p = 0;
        for (int i = 0; i < a.size(); i++) {
      int c = a[i] - 'a';
      if (nex[p][c]==false) return false;
      p = nex[p][c];
    }
    return ex[p];
    }
    void ins(string a){
        if(this->et(a)){
            return ;
        }
        int p = 0;
        for (int i = 0; i < a.size(); i++) {
      int c = a[i] - 'a';
      num[p]++;
      if (!nex[p][c]) nex[p][c] = ++cnt;  
      p = nex[p][c];
    }
    num[p]++;
    ex[p] = true;
    return;
    }
    int find(string a){
        int p=0;
        for(int i=0;i<a.size();i++){
            int c=a[i]-'a';
            if(nex[p][c]==0) return 0;
            p=nex[p][c];
        }
        return num[p];
    }
}date;
int main(){
    string a;
    for(int i=0;i<99999999;i++){
        getline(cin,a);
        if(a.empty())
        break;
        date.ins(a);
    }
    while(cin>>a){
        cout<<date.find(a)<<endl;
    }
    return 0;
}