#include<cstdio>
#include<algorithm>
int main (){
  int tol;
  long long tmp=0;
  int mint=999999999;
  int a[2][3];
  scanf("%d",&tol );
  for(int j=0;j<3;j++)
  for(int i=0;i<2;i++)
  {
  scanf("%d",&a[i][j] );
}
  for(int i=0;i<3;i++){

    if(tol%a[0][i]==0){
      tmp=tol/a[0][i]*a[1][i];
    }else{
      tmp=((tol/a[0][i])+1)*a[1][i];
    }
    if(mint>tmp){
      mint=tmp;
    }

  }
  printf("%d\n",mint );
  return 0;
}
