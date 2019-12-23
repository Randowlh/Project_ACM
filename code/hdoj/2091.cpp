#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    char tmp;
    int l;
    int flag=0;
    while(cin>>tmp){
        if(tmp=='@'){
            break;
        }
        cin>>l;
        if(flag==0)
        flag=1;
        else
        cout<<endl;
        int now=0;
        for(int i=0;i<l-1;i++){
            for(int j=0;j<l-1-now;j++){
                printf(" ");
            }
            printf("%c",tmp);
            if(now==0){
                for(int j=0;j<l-1-now;j++){
                    printf(" ");
                }
                now++;
                cout<<endl;
                continue;
            }else{
                for(int j=0;j<now*2-1;j++){
                    printf(" ");
                }
                printf("%c",tmp);
            }
            now++;
            printf("\n");
        }
        for(int i=0;i<l*2-1;i++){
            printf("%c",tmp);
        }
        cout<<endl;
    }
    return 0;
}