#include<cstdio>
#include<iostream>
using namespace std;
char date[1000];
int n;
int check(){
    int flag1=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        if(flag1==0){
            ans++;
        }
        if(flag1<0){
            return -1;
        }
        if(date[i]=='(')
            flag1++;
            else{
            flag1--;
            }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    int max1=-99;
    int maxx=0;
    int maxy=0;
    for(int i=0;i<n;i++)cin>>date[i];
    if(check()!=-1){
        printf("%d\n",check());
        printf("1 1\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
            swap(date[i],date[j]);
            if(check()!=-1){
                int tmp=check();
                if(max1<tmp){
                    max1=tmp;
                    maxx=i;
                    maxy=j;
                }
            }
            swap(date[i],date[j]); }
        }
    }
    if(max1!=-99){
        printf("%d\n",max1);
        printf("%d %d\n",maxx+1,maxy+1);
    }else{
        printf("0\n1 1\n");
    }
    return 0;
}