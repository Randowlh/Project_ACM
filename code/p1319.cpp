#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  int i,j,m,n;
  cin>>n;
  int flag =0;
  int cnt=0;
  while(cin>>m){
    if(flag==0){
      for(i=0;i<m;i++){
        cout<<0;
        cnt++;
        if(cnt==n){
          cout<<endl;
          cnt=0;
        }
      }
      flag=1;
    }else{
      for(i=0;i<m;i++){
        cout<<1;
        cnt++;
        if(cnt==n){
          cout<<endl;
          cnt=0;
        }
      }
      flag=0;
    }
  }
  return 0;
}
