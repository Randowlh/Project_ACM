#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void turns(int *arr){
    for(int j=0;j<3;j++){
    for(int i=0;i<2;i++)
    printf("%d ", *(arr + i*3 + j));
    cout<<endl;
  }
}
int main(){
  int block[3][3];
  memset(block,0,sizeof(block));
  for(int i=0;i<2;i++)
  for(int j=0;j<3;j++){
    scanf("%d",&block[i][j]);
  }
  turns(&block[0][0]);
  return 0;
}
