#include<cstdio>
#include<algorithm>
using namespace std;
int flag;
double mo,fa;
int main(){
    scanf("%d%lf%lf",&flag,&mo,&fa);
    if(flag==1){
        printf("%.1f\n",(mo+fa*0.923)/2.0);
    }else
    printf("%.1f\n",(mo+fa)*0.52);
    return 0;
}