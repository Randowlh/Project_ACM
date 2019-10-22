#include<cstdio>
int main(){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    int m;
    if(n%2==0){
        m=n/2;
    }else m=n/2+1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        printf("%c",c);
        printf("\n");
    }
    return 0;   
}
