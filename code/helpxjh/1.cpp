#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  for(int i=0;i<11;i++){
    for(int j=0;j<=11;j++){
      if(i<6){
        if(5-i<j&&j<=6+i){
          printf("* ");
        }
        else{
          printf("  ");
        }
      }
      else{
        if(i-5<j&&j<=16-i){
          printf("* ");
        }
        else
        printf("  " );
      }
    }
  printf("\n");
  }
  return 0;
}
