#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int now;
int backpack;
int rnd;
string date;
int tbackpack;
int main(){
    cin>>rnd;
    for(int q=0;q<rnd;q++){
        cin>>date;
        tbackpack=0;
        backpack=0;
        for(int i=0;i<date.size();i++){
            if(date[i]=='*'){
                tbackpack++;
                if(tbackpack>backpack){
                    backpack=tbackpack;
                    now=i;
                }
            }
            if(date[i]=='#'){
                tbackpack--;
                if(tbackpack<0){
                    break;
                }
            }
            if(date[i]=='.'){
                continue;
            }
        }
        cout<<backpack<<endl;
    }
    
    return 0;
}