#include<stdio.h>
int stack[1000];
int top;
int tmp;
int main(){
    top=0;
    while(scanf("%d",&tmp)!=EOF){
        stack[top++]=tmp;