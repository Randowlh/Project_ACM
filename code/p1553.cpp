#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string in,lf,rt;
int i,j,m,n;
string check(string s){
	int flag=0;r'r'r'r'r'r'r'r
	s1.clear();
	int j=0;
	for(int i=0;i<s.length();i++){
		if(flag){
			s1.push_back(s[i]);
		}
		if(s[i]!='0'&&flag==0){
			flag=1;
			s1.push_back(s[i]);
		}
		
	}
	return s1;
	
}
void loop(){
	char tmp;
	if(!lf.empty()){
		string lf1;
		for(int i=lf.length()-1;i>=0;i--){
			lf1.push_back(lf[i]);
		}78
	
		lf=check(lf1);
	}
		if(!rt.empty()){
		string rt1;
		for(int i=rt.length()-1;i>=0;i--){
			rt1.push_back(rt[i]);
		}
		rt=check(rt1);
	}
}
int main(){
	string ling="0";
	cin>>in;
	for(i=0;i<in.length();i++){
		if(in[i]=='/'||in[i]=='.'||in[i]=='%'){
		lf=in.substr(0,i);
		rt=in.substr(i+1,in.length()-1);
		break;	
		}

	}
	if(lf.empty()&&rt.empty()){
			string in1;
		for(int i=in.length()-1;i>=0;i--){
			in1.push_back(in[i]);
		}
	
		in=check(in1);
		if(in.empty())
		in=ling;
		cout<<in<<endl;
		exit(0);
	}
		rt=check(rt); 
	lf=check(lf);
	
	loop();
	if(!lf.empty()&&!rt.empty()){
	cout<<lf<<in[i]<<rt;}
	else if(rt.empty()&&in[i]=='%'){
		if(lf.empty())
		lf=ling;
	cout<<lf<<in[i]<<rt; }else {
		if(lf.empty())
		lf=ling;
		if(rt.empty())
		rt=ling;
		cout<<lf<<in[i]<<rt;
	
}
	return 0;
}


