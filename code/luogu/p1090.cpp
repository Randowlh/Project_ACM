#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue <int,vector<int>,greater<int> > arr;
int main(){
  int n=0;
  int tmp;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&tmp);
    arr.push(tmp);
  }
  int now=0;
  while(true){
    tmp=arr.top();
    arr.pop();
    if(arr.empty()){
      break;
    }
    now+=tmp+arr.top();
    arr.push(arr.top()+tmp);
    arr.pop();
  }
  printf("%d\n",now);
  return 0;
}
