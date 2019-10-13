#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    char c;
    double tmp;
    scanf("%c",&c);
    if(c=='F'){
    scanf("%lf",&tmp);
    printf("C %.2f",5.0/9.0*(tmp-32.0));
    }else{
        scanf("%lf",&tmp);
        printf("F %.2f",tmp*9.0/5.0+32.0);
    }
    return 0;
}