#include<stdio.h>
int main(){
    int x[10],*pt=x;
    for(int i=0;i<10;i++)x[i]=i;
    printf("%d\n%d\n",*(x+3),*(pt+10));
    return 0;
}