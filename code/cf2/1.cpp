#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  long long  j1;
  long long  o1;
  long long  j2;
  long long  o2;
  long long k;
  cin>>k;
  for(int q=0;q<k;q++){
      long long  n;
      j1=0;
      j2=0;
      o1=0;
      o2=0;
      long long  tmp=0;
    cin>>n;
      for(int i=0;i<n;i++){
          cin>>tmp;
        if(tmp%2==0){
            o1++;
        }else{
            j1++;
        }
      }
        cin>>n;
      for(int i=0;i<n;i++){
          cin>>tmp;
        if(tmp%2==0){
            o2++;
        }else{
            j2++;
        }
      }
      cout<<o1*o2+j1*j2<<endl;
  }
  return 0;  
}