#include<stdio.h>
#define Push(x) stack[top++]=x
int stack[1000];
int top;
int tmp;
int main(){
    while(scanf("%d",&tmp)!=EOF){
        stack[top++]=tmp;
    }
    for(int i=top-1;i>=0;i--){
        printf("%d ",stack[i]);
    }
    return 0;
}