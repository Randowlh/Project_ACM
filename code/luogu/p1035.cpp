#include<cstdio>
int main(){
double tol;
int a;
int i=1;
scanf("%d",&a);
while(true){
    tol+=1/(double)i;

    if(tol>(double)a){
      printf("%d",i);
      return 0;
    }
    i++;
}
return 0;
}
