#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int flag=0;
int year,mon,day;
int map[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
bool check(int  year){
    if(year%4==0&&year%100!=0){
        return true;   
    }else if(year%400==0){
        return true;
    }else return false;
}
int main(){
        int sum=0;
     while(scanf("%d/%d/%d",&year,&mon,&day)!=EOF){
    if(check(year)){
        sum=0;
        for(int i=1;i<mon;i++){
            sum+=map[1][i];
        }
        sum+=day;
        printf("%d\n",sum);
    }else{
        sum=0;
        for(int i=1;i<mon;i++){
            sum+=map[0][i];
        }
        sum+=day;
        printf("%d\n",sum);
    }
    }
    return 0;
}