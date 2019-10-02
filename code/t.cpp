#include<cstdio>
#include<cstring>
char arr[100000];
int main(){
    scanf("%s",arr);
    for(int i=0;i<strlen(arr);i++){
        printf("%c",*(arr+i));
    }
    return 0;
}