#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n>=3&&n<6){
        printf("Spring\n");
    }else if(n>=6&&n<9){
        printf("Summer\n");
    }else if(n>=9&&n<12)
        printf("Autumn\n");
        else 
        printf("Winter\n");
        return 0;
}