#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int book[27];
int book2[1000];
int main(){
    string tmp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        memset(book,0,sizeof(book));
        memset(book2,0,sizeof(book2));
        for(int j=0;j<tmp.size();j++){
            if(book2[j]==0){
                if(tmp[j]!=tmp[j+1]){
                    book[tmp[j]-'a']=1;
                }else{
                    book2[j]=1;
                    book2[j+1]=1;
                }
            }
        }
        for(int i=0;i<27;i++){
            if(book[i]==1){
                printf("%c",i+'a');
            }
        }
        printf("\n");
    }
    return 0;
}