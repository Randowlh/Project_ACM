#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  int f=1,s=1;
  for(int i=0;i<a.size();i++)
  f=f*(a[i]-'A'+1)%47;
  for(int i=0;i<b.size();i++)
  s=s*(b[i]-'A'+1)%47;
  if(s==f){
    printf("GO");
  }  else
    printf("STAY");
    return 0;
  }
