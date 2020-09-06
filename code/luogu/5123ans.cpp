#include<bits/stdc++.h>
using namespace std;
map<string,long long>f;
long long  n,Ans,ans;
string a[13],s;
int gcd(int a, int b){ return b ? gcd(b, a % b) : a;}
int main() {
	scanf("%lld",&n);
	Ans=n*(n-1)/2; //总共对数 
	for (int i=1;i<=n;i++) {
	   	for (int j=1;j<=5;j++) cin>>a[j];  
		sort(a+1,a+6);   //从小到大排序 
		int len=32;  
		ans=0;
		for (int i=1;i<len;i++) { //二进制枚举出所有情况 
			int cnt=0;string s="";
			for (int j=1;j<=5;j++)
			 if (i&(1<<(j-1))) {cnt++;s+="?"+a[j];} //将选出的口味用“？”连接出来 
			 if (cnt&1) ans+=f[s]++;  //奇数个则累加 
			  else ans-=f[s]++; //否则减去 
		}
		Ans-=ans; //减去和谐的，容斥 
	}
	printf("%lld\n",Ans);
	return 0;
} 