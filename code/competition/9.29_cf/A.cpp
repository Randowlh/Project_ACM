#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int map[11];
int  l,r;
bool check(int x){
    memset(map,0,sizeof(map));
    while(x^0){
        int tmp=x%10;
        if(map[tmp]==1){
            return false;
        }else{
            map[tmp]=1;
        }
        x=x/10;
    }
    return true;
}
int main(){
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(check(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}