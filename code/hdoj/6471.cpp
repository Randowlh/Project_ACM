#include<bits/stdc++.h> 
using namespace std;
int main(){
	string tmp1,tmp2;
	int t,n;
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n;
		cin>>tmp1>>tmp2;
		for(int i=0;i<tmp1.size();i++){
			if(tmp1[i]=='0')tmp1[i]='O';
			if(tmp2[i]=='0')tmp2[i]='O';
			if(tmp1[i]=='l')tmp1[i]='I';
			if(tmp2[i]=='l')tmp2[i]='I';
		}
		if(tmp1==tmp2)
		cout<<"OK"<<endl;
		else cout<<"NO"<<endl;
	}
}
