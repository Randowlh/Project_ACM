#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string fan[1010];
int tail1;
int tail2;
string da[1010];
int main(){
    while(getline(cin,fan[tail1])){
        if(fan[tail1]=="EOF"){
            tail1++;
            break;
        }else{
            tail1++;
        }
    }
    while(getline(cin,da[tail2])){
        if(da[tail2]=="EOF"){
            tail2++;
            break;
        }else{
            tail2++;
        }
    }
    unsigned long long ans=0;
    for(int i=0;i<tail1-1;i++){
        int pianyi=0;
        for(int j=0;j<da[i].size();j++){
            if(da[i][j] == '<'){
                pianyi+=2;
            }else{
                if(da[i][j]==fan[i][j-pianyi]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;

    
}