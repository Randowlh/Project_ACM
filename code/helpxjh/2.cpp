#include<iostream>
using namespace std;
int main(){
  for(int i=0;i<5;i++){
    for(int j=0;j<11;j++){
      if(j==0||j==10){
        cout<<"* ";
        continue;
      }

      if(j==i||j==(10-i)){
        cout<<"* ";
        continue;
      }
      cout << "  ";
    }
    cout<<endl;
  }
  for(int i=0;i<11;i++){
    cout<<"* ";
  }
  cout<<endl;
  return 0;
}
