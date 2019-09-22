#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node
{
 int x;
	bool operator < (const node &a)const
	{
		return x < a.x;         
}};
bool cmp (struct node a,struct node b){
  return a.x>b.x;
}
int main(){
  priority_queue<  node > pq;
  return 0;
}