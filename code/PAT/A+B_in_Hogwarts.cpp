#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d,e,f;
int ans1,ans2,ans3;
int main(){
  scanf("%d.%d.%d",&a,&b,&c);
  scanf("%d.%d.%d",&d,&e,&f);
  if(c+f>28){
    ans3+=(c+f)%29;
    b+=(c+f)/29;
  }else{
    ans3=c+f;
  }
  if(b+e>17){
    ans2+=(b+e)%17;
    a+=(b+e)/17;
  }else{
    ans2=b+e;
  }
  ans1=a+d;
  printf("%d.%d.%d\n",ans1,ans2,ans3);
  return 0;
}
