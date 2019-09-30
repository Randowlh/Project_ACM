#include<cstdio>
#include<algorithm>
using namespace std;
int a[4];
int main(){
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+4);
    if(a[1]+a[2]==a[0]+a[3]){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}