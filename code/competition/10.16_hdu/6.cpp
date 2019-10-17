#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char date[100100];
char tmp;
int tail;
int main(){
    int flag=0;
    tail=0;
    int flag1=0;
    while(true){
        long long ans=0;
        if(flag==1){
            break;
        }
        tail=0;
        while(true){
        tmp=getchar();
        if(tmp==EOF){
            return 0;
        }
        if(tmp=='"'){
            if(flag1==1){
                flag1=0;
            }else{
                flag1=1;
            }
        }
        if(tmp=='\n'&&flag1==0){
            break;
        }
        if(tmp!='\n'){
            date[tail]=tmp;
            tail++;
        }
        }
        for(int i=0;i<tail;i++){
            if((date[i]>='a'&&date[i]<='z')){
                ans+=date[i]-'a'+1;
            }else if((date[i]>='A'&&date[i]<='Z')){
                ans+=date[i]-'A'+1;
            }else continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}