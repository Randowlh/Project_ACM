#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int i,j,m,n,d;
  scanf("%d",&d);
  string ss,ans;
  cin>>ss;
  int flag=0;
  for(i=0;i<ss.length();i++){
    if(flag==0&&ss[i]!='0'){
      flag=1;
      cout<<ss[i]<<'*'<<d<<'^'<<ss.length()-1-i;
    }else if(ss[i]!='0'){
      cout<<'+'<<ss[i]<<'*'<<d<<'^'<<ss.length()-1-i;
    }
  }
  return 0;
}
