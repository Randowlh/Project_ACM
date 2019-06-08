#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,x[100],y[100],r[100],x1,x2,y1,y2;
int dis(int n,int flag){
  if(flag==1){
    return (x1-x[n])*(x1-x[n])+(y1-y[n])*(y1-y[n]);
  }else return (x2-x[n])*(x2-x[n])+(y2-y[n])*(y2-y[n]);
}
int main(){
	int i,j;
  scanf("%d",&n);
  for( i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&y[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  int ans=0;
  for( i=1;i<n;i++){
    if(r[i]*r[i]>dis(n,0)){
      ans++;
      break;
    }
  }
  for( j=1;j<n;j++){
    if(r[i]*r[i]>dis(n,0)){
      ans++;
      break;
    }
  }
  if(i==j){
    cout<<0<<endl;
  }else{
    cout<<ans<<endl;
  }
  return 0;
  
}
