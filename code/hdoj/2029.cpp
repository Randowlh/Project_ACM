#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string tmp;
    while(cin>>n){
        for(int q=0;q<n;q++){
        cin>>tmp;
        
        int flag=0;
        for(int i=0;i<=(tmp.size()-1)/2;i++){
            if(tmp[i]!=tmp[tmp.size()-1-i]){
                flag=1;
            }
        }
        if(flag==1){
            printf("no\n");
        }else{
            printf("yes\n");
        }
        }
    }
    return 0;
}