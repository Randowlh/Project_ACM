#include<cstdio>
int main(){
    double h,w;
    scanf("%lf%lf",&h,&w);
    if(w>=h-110+5){
        printf("fat\n");
    }else if(w<=h-110-5){
        printf("thin\n");
    }else printf("good\n");
    return 0;
}