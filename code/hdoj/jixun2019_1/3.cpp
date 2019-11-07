#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string tmp;
int map[270][270];
int book[270];
int flag=0;
void dfs(int now){
   // printf("%c\n",now+'a');
    if(now=='m'-'a'){
        flag=1;
    }
    if(flag==1)
    return ;
    for(int i=0;i<=26;i++){
        if(book[i]==0&&map[now][i]==1){
            book[i]=1;
            dfs(i);
            book[i]=0;
        }
    }
    return ;
}
int main(){
    //int a[6]={1,,,3};
    //freopen("a.in","r",stdin);
    memset(map,0,sizeof(map));
    while(cin>>tmp){   
        if(tmp=="0"){
            flag=0;
            memset(book,0,sizeof(book));
            book['b'-'a']=1;
            dfs('b'-'a');
            if(flag==1){
                printf("Yes.\n");
            }else{
                printf("No.\n");
            }
            memset(map,0,sizeof(map));
        }else{
            map[tmp[0]-'a'][tmp[tmp.size()-1]-'a']=1;
            continue;
        }
    }
    return 0;
}