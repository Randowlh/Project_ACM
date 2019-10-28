#include<iostream>
using namespace std;
double my_pow(double a,int b){
	if(b<0)return 1/my_pow(a,-b);
	double ans=1;
	int k=1;
	double tmp=a;
	if(b==0)return 1;
	while(b>=k){
		ans=tmp*ans;
		tmp=tmp*tmp;
		b-=k;
		k+=k;
	}
	if(b!=0){
		ans*=my_pow(a,b);
	}
	return ans;
}
int main(){
	double a;
	int b;
	cin>>a>>b;
	cout<<my_pow(a,b)<<endl;
	return 0;
}